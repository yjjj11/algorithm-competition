#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
signed main(){
    int n,M,w[1005],v[1005],dp[1005],g[1005];
    cin>>n>>M;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    dp[0]=0,g[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=M;j>=w[i];j--){
            int temp=max(dp[j],dp[j-w[i]]+v[i]),c=0;
            if(temp==dp[j])c=(c+g[j])%mod;
            if(temp==dp[j-w[i]]+v[i])c=(c+g[j-w[i]])%mod;
            dp[j]=temp;
            g[j]=c;
        }
    }
    int ans=0;
    for(int i=0;i<=M;i++){
        if(dp[i]==dp[M]){
            ans=(ans+g[i])%mod;
        }
    }
    cout<<ans;
}
