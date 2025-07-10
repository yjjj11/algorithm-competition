#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n+1];
        map<int,int>mp;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int p_su[n+1];
        p_su[0]=0;
        int lst[n+1];
        mp[0]=0;
        for(int i=1;i<=n;i++){
            p_su[i]=p_su[i-1]+a[i];
            if(mp.find(p_su[i])==mp.end()){
                lst[i]=-1;
            }
            else{
                lst[i]=mp[p_su[i]];
            }
            mp[p_su[i]]=i;
        }
        int dp[n+1];
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;i++){
            dp[i]=max(dp[i],dp[i-1]);
            if(lst[i]!=-1){
                dp[i]=max(dp[i],dp[lst[i]]+1);
            }
        }
        cout<<*max_element(dp,dp+n+1)<<endl;
    }
}