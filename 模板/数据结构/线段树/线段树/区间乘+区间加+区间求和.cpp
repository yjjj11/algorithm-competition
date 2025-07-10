#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,p,a[N];
struct node{
    int l,r;
    int add,mul;
    int sum;
}tr[N*4];
void pushup(int u){
    tr[u].sum=(tr[u<<1].sum+tr[u<<1|1].sum)%p;
}
void build(int u,int l,int r){
    if(l==r) tr[u]={l,r,0,1,a[l]%p};
    else{
        tr[u].l=l,tr[u].r=r;
        int mid=(l+r)/2;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        pushup(u);
    }
}
void pushdown(int u){
    node &l=tr[u<<1];
	node &r=tr[u<<1|1];
	node &root=tr[u];
	l.sum=(l.sum*root.mul+root.add*(l.r-l.l+1))%p;
	l.mul=(l.mul*root.mul)%p;
	l.add=(l.add*root.mul+root.add)%p;
	r.sum=(r.sum*root.mul+root.add*(r.r-r.l+1))%p;
	r.mul=(r.mul*root.mul)%p;
	r.add=(r.add*root.mul+root.add)%p;
	root.add=0,root.mul=1;
}
void modify(int u,int l,int r,int x,int p){
    if(tr[u].l>=l&&tr[u].r<=r){
        if(p==0){
            tr[u].add=(tr[u].add+x)%p;
            tr[u].sum=(tr[u].sum+(tr[u].r-tr[u].l+1)*x%p)%p;
        }
        else if(p==1){
            tr[u].mul=tr[u].mul*x%p;
            tr[u].sum=tr[u].sum*x%p;
			tr[u].add=tr[u].add*x%p;
        }
        return;
    }
    pushdown(u);
    int mid=(tr[u].l+tr[u].r)/2;
    if(l<=mid) modify(u<<1,l,r,x,p);
    if(r>mid) modify(u<<1|1,l,r,x,p);
    pushup(u);
}
int query(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r) return tr[u].sum;
    pushdown(u);
    int mid=(tr[u].l+tr[u].r)/2;
    int res=0;
    if(l<=mid) res=query(u<<1,l,r);
    if(r>mid) res=(res+query(u<<1|1,l,r))%p;
	pushup(u);
    return res;
}
int main(){
    cin>>n>>p;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    cin>>m;
    for(int i=1;i<=m;i++){
        int op;
        int l,r;
        cin>>op;
        if(op==1){
            cin>>l>>r;
            int x;
            cin>>x;
            modify(1,l,r,x,1);
        }
        else if(op==2){
            cin>>l>>r;
            int x;
            cin>>x;
            modify(1,l,r,x,0);
        }
        else {
            cin>>l>>r;
            cout<<query(1,l,r)<<"\n";
        }
    }
}
