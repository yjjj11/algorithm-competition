#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,pi=3.1415926535;
#define int long long
int n,m,a[N],b[N];
struct node{
    int l,r,num;
}tr[N*4];
void build(int u,int l,int r){
    tr[u].l=l,tr[u].r=r;
    if(l==r){
        tr[u].num=0;
        return;
    }
    int mid=(l+r)>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
}
void insert(int u,int x){
    if(tr[u].l==tr[u].r){
        tr[u].num++;
        return;
    }
    int mid=(tr[u].l+tr[u].r)>>1;
    if(x<=mid)insert(u<<1,x);
    else insert(u<<1|1,x);
    tr[u].num=tr[u<<1].num+tr[u<<1|1].num;
}
int query1(int u,int k){
    if(tr[u].l==tr[u].r)return b[tr[u].l];//tr[u].l是离散后对应的序号
    int mid=(tr[u].l+tr[u].r)>>1;
    if(k<=tr[u<<1].num)return query1(u<<1,k);
    else return query1(u<<1|1,k-tr[u<<1].num);
}
int query2(int u,int l,int r){//查询一个权值区间的数的个数
    if(tr[u].l>=l&&tr[u].r<=r)return tr[u].num;
    int mid=(tr[u].l+tr[u].r)>>1;
    int res=0;
    if(l<=mid)res+=query2(u<<1,l,r);
    if(r>mid)res+=query2(u<<1|1,l,r);//收集关于l,r的区间信息；
    return res;
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    int len = unique(b + 1, b + n + 1) - b - 1;
    for(int i=1;i<=n;i++){
        a[i]=lower_bound(b+1,b+len+1,a[i])-b;
    }//离散化为相对大小序号
    build(1,1,len);

    //查找全局第k小find（）
    for(int i=1,k=1;i<=n;i+=2,k++){
        if(i>1)insert(1,a[i-1]);
        insert(1,a[i]);
        cout<<query1(1,k)<<"\n";
    }

    //查找某个数出现的个数
    //查找一段区间的数出现的次数query2()
}

