#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,M,w[1005],v[1005],dp[1005][1005];
    string s[1005];
    memset(dp,0,sizeof dp);
    for(int i=1;i<=n;i++)s[i]="";
    cin>>n>>M;
    for(int i=1;i<=n;i++)cin>>w[i]>>v[i];
    for(int i=n;i>=1;i--){
        for(int j=0;j<=M;j++){
            dp[i][j]=dp[i+1][j];
            if(j>=w[i])dp[i][j]=max(dp[i][j],dp[i+1][j-w[i]]+v[i]);
        }
    }
    for(int i=1,j=M;i<=n;i++){
        if(j>=w[i]&&dp[i][j]==dp[i+1][j-w[i]]+v[i]){
            cout<<i<<" ";
            j-=w[i];
        }
    }
}
