#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m,q,a[N],b[N],cnt=0;
        pair<int,int>p[N];
        cin>>n>>m>>q;
        queue<int>st;
        map<int,int>mp,mpp;
        for(int i=1;i<=n;i++) cin>>a[i],st.push(a[i]);
        for(int i=1;i<=m;i++) cin>>b[i];
        for(int i=1;i<=m;i++){
            if(mp[b[i]]==0){
                mp[b[i]]=1;
                p[++cnt]={b[i],i};
                mpp[i]=b[i];
            }
        }
        while(q--){
            int pos,k;
            cin>>pos>>k;
            if(mpp[pos]==){
        }
    }
}