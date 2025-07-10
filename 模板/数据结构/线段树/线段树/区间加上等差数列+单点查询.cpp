#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],m;
struct node{
    int l,r;
    int sum,add;
}tr[100005*4];
void pushdown(int u){
    node &me=tr[u],&l=tr[u<<1],&r=tr[u<<1|1];
    l.add+=me.add,r.add+=me.add;
    l.sum+=(l.r-l.l+1)*me.add,r.sum+=(r.r-r.l+1)*me.add;
    me.add=0;
}
void pushup(int u){
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}
void build(int u,int l,int r){
    if(l==r)tr[u]={l,r,a[l],0};
    else{
        tr[u]={l,r};
        int mid=(tr[u].l+tr[u].r)/2;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        pushup(u);
    }
}
int query(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r)return tr[u].sum;
    else{
        pushdown(u);
        int mid=(tr[u].l+tr[u].r)/2,sum=0;
        if(l<=mid)sum=query(u<<1,l,r);
        else if(r>mid)sum+=query(u<<1|1,l,r);
        return sum;
    }
    
}
void modify(int u,int l,int r,int d){
    if(tr[u].l>=l&&tr[u].r<=r){
        tr[u].add+=d;
        tr[u].sum+=(tr[u].r-tr[u].l+1)*d;
    }
    else{
        pushdown(u);
        int mid=(tr[u].l+tr[u].r)/2;
        if(l<=mid)modify(u<<1,l,r,d);
        else if(r>mid)modify(u<<1|1,l,r,d);
        pushup(u);
    }
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n-1;i>=1;i--)a[i+1]=a[i+1]-a[i];
    a[0]=0;
    build(1,1,n);
    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int l,r,k,d;
            cin>>l>>r>>k>>d;
            modify(1,l,l,k);//单点修改
            if(l+1<=r)modify(1,l+1,r,d);//区间修改
            if(r+1<=n)modify(1,r+1,r+1,-(k+(r-l)*d));
        }
        else if(op==2){
            int p;
            cin>>p;
            cout<<query(1,1,p)<<"\n";
        }
    }
}
