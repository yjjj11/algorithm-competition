#include <bits/stdc++.h>
#define int long long
#define fi first 
#define se second
#define all(v) v.begin(),v.end()
using namespace std;
const int inf = 0x3f3f3f3f3f3f3f;
const int N = 1e6+5;
int n,k;
int a[N];
int pre[N];
int dp[N][2];
 
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n+1;i++)pre[i] = 0;
    for(int i=1;i<=n;i++)cin>>a[i];
 
    if(k == 1){
        int sum = 0;
        for(int i=1;i<=n;i++)sum += a[i];
        cout<<sum<<"\n";
        return;
    }
    for(int i=0;i<=n+1;i++){
        dp[i][0] = dp[i][1] = 0;
    }
 
    for(int i=1;i<=n;i++){
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
        if(i-k>=0){
            dp[i][1] = max({dp[i-1][1],dp[i-k][0],dp[i-k][1]}) + a[i];
        }
    }
    //状态机表示
    cout<<max(dp[n][0],dp[n][1])<<"\n";
 
     
}
 
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}