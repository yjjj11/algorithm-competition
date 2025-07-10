#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,inf=1e18;
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
bool cmp(pii a,pii b){
    return a.y>b.y;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,aa=0,bb=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            int x,y;
            cin>>x>>y;
            aa=max(aa,x),bb=max(bb,y);
        }
        cout<<(aa+bb)*2<<"\n";
    }
}