#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 2e5+10;
int n,m,a[N];
struct zxTree{
    int ls,rs,sum;//左右儿子,区间内元素个数
    #define ls(x) tr[x].ls
    #define rs(x) tr[x].rs
    #define sum(x) tr[x].sum
} tr[N*40];//注意数组大小
int sz = 0;//不同版本的树的总数 
int root[N];//root[i]存放第i棵树的树根的编号
int BuildTree(int l,int r){
    /*建树,和普通线段树相同*/
    int rt = ++sz;sum(rt) = 0;
    if(l == r) return rt;
    int mid = l+r>>1;
    ls(rt) = BuildTree(l,mid);
    rs(rt) = BuildTree(mid+1,r);
    return rt;
}
int updata(int pre,int l,int r,int x){
    /*新建一棵树,其比pre树多一个元素x*/
    int rt = ++sz;
    tr[rt] = tr[pre]; sum(rt)++;
    if(l == r) return rt;
    int mid = l+r>>1;
    if(x <= mid) ls(rt) = updata(ls(pre),l,mid,x);
    else rs(rt) = updata(rs(pre),mid+1,r,x);
    return rt;
}
int ask(int pre,int rt,int l,int r,int k){
    /*  依次是:上一个树根,当前树根,区间左右端点,所求区间第k大
        返回该区间第k大数的下标 */
    if(l >= r) return l;
    int res = sum(ls(rt)) - sum(ls(pre));
    int mid = l+r>>1;
    if(res >= k) return ask(ls(pre),ls(rt),l,mid,k);
    else return ask(rs(pre),rs(rt),mid+1,r,k-res);
}
int tmp[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++) scanf("%d",a+i),tmp[i] = a[i];
    //离散化
    sort(tmp+1,tmp+1+n);
    int tot = unique(tmp+1,tmp+1+n)-tmp-1;
    root[0] = BuildTree(1,tot);
    for(int i = 1;i <= n;i++){
        int x = lower_bound(tmp+1,tmp+1+tot,a[i])-tmp;
        root[i] = updata(root[i-1],1,tot,x);
    }
    //利用主席树可以加减原理计算
    for(int i = 1,l,r,k;i <= m;i++){
        scanf("%d%d%d",&l,&r,&k);
        int x = ask(root[l-1],root[r],1,tot,k);
        printf("%d\n",tmp[x]);
    }
    return 0;
}
