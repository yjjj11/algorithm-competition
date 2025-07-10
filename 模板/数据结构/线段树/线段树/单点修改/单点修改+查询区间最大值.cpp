#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int m,p,a,cnt;
struct node{
    int l,r;
    int v;
}tr[N*4];
void build(int u,int l,int r){//递归过程中l,r则两个参数是不可以变动的
    tr[u]={l,r};
    if(l==r)return;
    int mid=(l+r)/2;
    build(u*2,l,mid),build(u*2+1,mid+1,r);
}
int query(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r)return tr[u].v;
    int mid=(tr[u].l+tr[u].r)/2;
    int res=0;
    if(l<=mid)res=query(u*2,l,r);
    if(r>mid)res=max(res,query(u*2+1,l,r));
    return res;
}
void modify(int u,int x,int v){
    if(tr[u].l==x&&tr[u].r==x)tr[u].v=v;
    else{
        int mid=(tr[u].l+tr[u].r)/2;
        if(x<=mid)modify(u*2,x,v);
        else modify(u*2+1,x,v);
        tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
    }
}
signed main(){
    cin>>m>>p;
    build(1,1,m);
    while(m--){
        string op;
        cin>>op;
        if(op=="A"){
            int t;
            cin>>t;
            modify(1,cnt+1,(t+a)%p);
            cnt++;
        }
        else{
            int t;
            cin>>t;
            a=query(1,cnt-t+1,cnt);
            cout<<a<<"\n";
        }
    }
}
