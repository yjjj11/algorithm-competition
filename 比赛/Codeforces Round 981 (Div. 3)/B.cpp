#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,a[505][505];
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                cin>>a[i][j];
        }
        int ans=0;
        map<int,int>mp;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i][j]<0){
                    mp[j-i]=min(mp[j-i],a[i][j]);
                }
            }
        }
        for(int i=-n+1;i<=n;i++){
            if(mp[i]!=0)ans-=mp[i];
        }
        cout<<ans<<endl;
    }
}