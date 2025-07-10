#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,mod=1e9+7;
int n,q,a[N];
struct node{
    int l,r;
    int sum=0,tag=0,mul=1;
}tr[N<<2];
int ppow(int a,int b){
    int res=1;
    while(b){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
void pushup(node& cur,node& l,node& r){
    cur.sum=(l.sum + r.sum * l.mul % mod) % mod;
    cur.mul=l.mul*r.mul%mod;
}
void pushup(int u){
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}
void pushdown(int u){
    node &l=tr[u<<1],&r=tr[u<<1|1],&cur=tr[u];
    if(cur.tag){
        l.tag=r.tag=cur.tag;
        l.mul=ppow(cur.tag,l.r-l.l+1)%mod;
        r.mul=ppow(cur.tag,r.r-r.l+1)%mod;
        l.sum=cur.tag*ppow(cur.tag-1,mod-2)%mod*(l.mul-1)%mod;
        r.sum=cur.tag*ppow(cur.tag-1,mod-2)%mod*(r.mul-1)%mod;
        if(cur.tag==1){
            l.sum=l.r-l.l+1;
            r.sum=r.r-r.l+1;
        }
        cur.tag=0;
    }
}
void build(int u,int l,int r){
    if(l==r)tr[u]={l,r,a[l],0,a[l]};
    else{
        tr[u]={l,r};
        int mid=(l+r)>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}
void update(int u,int l,int r,int x){
    if(tr[u].l>=l&&tr[u].r<=r){
        int len=tr[u].r-tr[u].l+1;
        tr[u].tag=x;
        tr[u].mul=ppow(x,len)%mod;
        if(x==1){
            tr[u].sum=len;
            tr[u].mul=1;
        } else {
            tr[u].sum=x*ppow(x-1,mod-2)%mod*(tr[u].mul-1)%mod;
        }
        return ;
    }
    pushdown(u);
    int mid=(tr[u].l+tr[u].r)>>1;
    if(l<=mid)update(u<<1,l,r,x);
    if(r>mid)update(u<<1|1,l,r,x);
    pushup(u);
}
node query(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r)return tr[u];
    pushdown(u);
    int mid=(tr[u].l+tr[u].r)>>1;
    if(r<=mid)return query(u<<1,l,r);
    else if(l>mid)return query(u<<1|1,l,r);
    else{
        node res,ll,rr;
        ll=query(u<<1,l,r),rr=query(u<<1|1,l,r);
        pushup(res,ll,rr);
        return res;
    }
}
signed main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    while(q--){
        int op,l,r,x;
        cin>>op;
        if(op==1){
            cin>>l>>r>>x;
            update(1,l,r,x);
        }
        else if(op==2){
            cin>>l>>r;
            int ans=query(1,l,r).sum;
            cout<<ans<<"\n";
        }
    }
}
