#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 200010;
int n,q;
int a[N];
struct segtree{
    int l,r;
    int val,sum;
    int sl,sr;
    int al,ar;
    int lazy;
}tr[N<<2];
void pushup(segtree &u,segtree &l,segtree &r){
    u.l=l.l;u.r=r.r;
    u.val=max(l.val,r.val);
    u.sum=l.sum+r.sum;
 
    if(l.ar==r.al){
        u.sum--;
        u.val=max(u.val,l.sr+r.sl);
    }
    u.al=l.al,u.ar=r.ar;
    u.sl=l.sl,u.sr=r.sr;
    if(l.ar==r.al && (l.r-l.l+1)==l.sl){
        u.sl=l.sl+r.sl;
    }
    if(l.ar==r.al && (r.r-r.l+1)==r.sr){
        u.sr=r.sr+l.sr;
    }    
}
 
void pushup(int u){
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}
 
void pushdown(int u){
    if(tr[u].lazy!=-1){
        tr[u<<1].lazy=tr[u].lazy;
        tr[u<<1|1].lazy=tr[u].lazy;
 
        tr[u<<1].sl=tr[u<<1].sr=tr[u<<1].val=(tr[u<<1].r-tr[u<<1].l+1);
        tr[u<<1].sum=1;
        tr[u<<1].al=tr[u<<1].ar=tr[u].lazy;
 
        tr[u<<1|1].sl=tr[u<<1|1].sr=tr[u<<1|1].val=(tr[u<<1|1].r-tr[u<<1|1].l+1);
        tr[u<<1|1].sum=1;
        tr[u<<1|1].al=tr[u<<1|1].ar=tr[u].lazy;
 
        tr[u].lazy=-1;        
    }
 
}
 
void build(int u,int l,int r){
    if(l==r){
        tr[u]={l,r,1,1,1,1,a[l],a[l],-1};
        return;
    }
    tr[u]={l,r};
    tr[u].lazy=-1;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}
 
void modify(int u,int l,int r,int d){
    if(tr[u].l>=l && tr[u].r<=r){
        tr[u].sl=tr[u].sr=tr[u].val=(tr[u].r-tr[u].l+1);
        tr[u].sum=1;
        tr[u].al=tr[u].ar=d;
        tr[u].lazy=d;
        return;
    }
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    if(l<=mid) modify(u<<1,l,r,d);
    if(r>mid) modify(u<<1|1,l,r,d);
    pushup(u);
}
 
segtree query(int u,int l,int r){
    if(tr[u].l>=l && tr[u].r<=r){
        return tr[u];
    }
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    if(r<=mid) return query(u<<1,l,r);
    else if(l>mid) return query(u<<1|1,l,r);
    else{
        auto left=query(u<<1,l,r);
        auto right=query(u<<1|1,l,r);
        segtree res;
        pushup(res,left,right);
        return res;
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    cin>>q;
    while(q--){
        int op,l,r;
        cin>>op>>l>>r;
        if(op==1){
            int c;cin>>c;
            modify(1,l,r,c);
        }
        if(op==2){
            auto tt=query(1,l,r);
            cout<<tt.sum<<endl;
        }
        if(op==3){
            auto tt=query(1,l,r);
            cout<<tt.val<<endl;
        }
    }
}
 
signed main(){
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    srand(time(0));
    int T=1;//cin>>T;
    while(T--){
        solve();
    }
}