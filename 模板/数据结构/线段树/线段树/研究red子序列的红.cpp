#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define mod 998244353
#define maxn 200005
struct node{
    int r=0,e=0,d=0,re=0,ed=0,red=0;
    const node operator+(const node& b)const{
        node res;
        res.r=r+b.r;
        res.e=e+b.e;
        res.d=d+b.d;
        res.re=re+b.re+r*b.e;
        res.ed=ed+b.ed+e*b.d;
        res.red=red+b.red+re*b.d+r*b.ed;
        return res;
    }
}seg[4*maxn][2];
void build(int node, int l, int r, string& s, int m){
    if(l==r){
        seg[node][m]={0,0,0,0,0,0};
        if(s[l]=='r') seg[node][m].r=1;
        else if(s[l]=='e') seg[node][m].e=1;
        else if(s[l]=='d') seg[node][m].d=1;
        return;
    }
    int mid=(l+r)/2;
    build(2*node,l,mid,s,m);
    build(2*node+1,mid+1,r,s,m);
    seg[node][m]=seg[2*node][m]+seg[2*node+1][m];//pushup;
}
void update(int node, int l, int r, int loc,char c,int m){
    if(l==r){
        seg[node][m]={0,0,0,0,0,0};
        if(c=='r') seg[node][m].r=1;
        else if(c=='e') seg[node][m].e=1;
        else if(c=='d') seg[node][m].d=1;
        return;
    }
    int mid=(l+r)/2;
    if(loc<=mid) update(2*node,l,mid,loc,c,m);
    else update(2*node+1,mid+1,r,loc,c,m);
    seg[node][m]=seg[2*node][m]+seg[2*node+1][m];
}
int query(){
    return seg[1][0].red-seg[1][1].red;
}
void solve(){
    int n,q;
    cin>>n>>q;
    string s,t;
    cin>>s>>t;
    build(1,0,n-1,s,0);
    build(1,0,n-1,t,1);
    while(q--){
        int loc;
        cin>>loc;
        if(s[loc-1]==t[loc-1]){
            cout<<query()<<endl;
        }
        else{
            update(1,0,n-1,loc-1,t[loc-1],0);
            update(1,0,n-1,loc-1,s[loc-1],1);
            swap(s[loc-1],t[loc-1]);
            cout<<query()<<endl;
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    t=1;
    while (t--) {
        solve();
    }
    return 0;
}