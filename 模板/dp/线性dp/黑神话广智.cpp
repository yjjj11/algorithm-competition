#include<bits/stdc++.h>
typedef  long long ll;
typedef unsigned long long  ULL;
using namespace std;
const ll N = 2e6+10;
ll n,q;
ll ans[N];
ll dp[N];  //还剩i的血量的最小消耗
ll a,b,c,d;
void solve()
{
    cin>>n;
    cin>>a>>b>>c>>d;
    for(int i=1;i<=n;i++)  {
        cin>>ans[i];
    }
    for(int i=0;i<=n;i++)  dp[i]=1e17;
    dp[n]=0;
    for(int i=n;i>=1;i--){
        dp[max(i-b,0ll)]=min(dp[max(i-b,0ll)],dp[i]+a);
        dp[max(i-d,0ll)]=min(dp[max(i-d,0ll)],dp[i]+c);
        //if(i+d+4*b+ans[i+d]<=n) dp[i]=min(dp[i],dp[i+d+4*b+ans[i+d]]+a+c);
        if(i-4*b>0) dp[max(i-4*b-d-ans[i-4*b],0ll)]=min(dp[max(i-4*b-d-ans[i-4*b],0ll)],dp[i]+4*a+c);
    }
    //for(int i=0;i<=n;i++)  cout<<dp[i]<<" ";
    //cout<<endl;
    cout<<dp[0]<<endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    ll t=1;
    cin>>t;
    while(t--){
        solve();
    }
}