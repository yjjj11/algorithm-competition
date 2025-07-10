// https://blog.csdn.net/weixin_41162823/article/details/100145918?ops_request_misc=%257B%2522request%255Fid%2522%253A%25222077f8f941becd879f0e995bf67cb58f%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=2077f8f941becd879f0e995bf67cb58f&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-100145918-null-null.142^v100^pc_search_result_base6&utm_term=%E4%B8%BB%E5%B8%AD%E6%A0%91&spm=1018.2226.3001.4187
#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10;
struct node{
    int l,r,sum;//l和r为左右子树
}tr[maxn*22];
int root[maxn],n,a[maxn],cnt,b[maxn],m;
int build(int l,int r){//l和r只是为了搜索
    int u=++cnt;
    tr[u].sum=0;
    if(l==r) return u;
    int mid=(l+r)>>1;
    tr[u].l=build(l,mid);
    tr[u].r=build(mid+1,r);
    return u;
}//建造初始版本
int update(int pre,int l,int r,int x){
    int u=++cnt;//取代新节点
    tr[u]=tr[pre];
    tr[u].sum++;
    if(l==r) return u;
    int mid=(l+r)>>1;
    if(x<=mid)tr[u].l=update(tr[pre].l,l,mid,x);//哪边要修改就往哪边走
    else tr[u].r=update(tr[pre].r,mid+1,r,x);
    return u;
}//建造 历史版本的线段树
//因为只要log2就可以找到l==r所以一共递归log2次，修改路径上的所有点

int query(int pre,int now,int l,int r,int k){
    if(l==r)return b[l];
    int s=tr[tr[now].l].sum-tr[tr[pre].l].sum;//两个节点的左孩子的sum进行比较
    int mid=(l+r)>>1;
    if(k<=s)return query(tr[pre].l,tr[now].l,l,mid,k);
    else return query(tr[pre].r,tr[now].r,mid+1,r,k-s);
}
int main(){
    int n;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    int tot=unique(b+1,b+1+n)-b-1;
    root[0]=build(1,tot);
    for(int i=1;i<=n;i++){
        int x=lower_bound(b+1,b+tot+1,a[i])-b;
        root[i]=update(root[i-1],1,tot,x);//前缀线段树
    }
    while(m--){
        int l,r;
        cin>>l>>r;
        int k=(r-l)/2+1;
        cout<<query(root[l-1],root[r],1,tot,k)<<"\n";
    }
}
