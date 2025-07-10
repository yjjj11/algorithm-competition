#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,pi=3.1415926535;
#define int long long
int n,a[N],b[N];
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
    tr[u].num=tr[u<<1].num+tr[u<<1|1].num;//pushup操作回溯
}
int query(int u,int l,int r){//查询一个权值区间的数的个数
    if(tr[u].l>=l&&tr[u].r<=r)return tr[u].num;
    int mid=(tr[u].l+tr[u].r)>>1;
    int res=0;
    if(l<=mid)res+=query(u<<1,l,r);
    if(r>mid)res+=query(u<<1|1,l,r);//收集关于l,r的区间信息；
    return res;
}
signed main(){
    int res=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    int tot=1;
    for(int i=2;i<=n;i++){
        if(b[i]!=b[tot]){
            b[++tot]=b[i];
        }
    }//去重操作
    for(int i=1;i<=n;i++){
        a[i]=lower_bound(b+1,b+tot+1,a[i])-b;
    }//离散化为相对大小序号
    build(1,1,tot);
    for(int i=1;i<=n;i++){
        insert(1,a[i]);
        res+=query(1,a[i]+1,tot);//查询已插入的且大于a[i]的数的个数
    }
    cout<<res<<"\n";
}

