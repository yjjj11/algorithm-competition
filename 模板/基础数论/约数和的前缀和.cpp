#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f 
#define GG ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define cnot cout<<"NO"<<"\n"
#define cyes cout<<"YES"<<"\n"
#define cans cout<<ans<<"\n"
#define pb push_back
#define x0 first
#define y0 second
#define lc p<<1
#define rc p<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef pair<int,string>Pis;
typedef pair<int,int>Pii;
const int N=2e5+10,mod=998244353,M=1e6+10;
int lowbit(int x){
return x&(-x);}
int calc(int x){
    int sum=0;
    int id=0;
    for(int l=1,r;l<=x;l=r+1){
        r=x/(x/l);
        sum+=(x/l)%mod*(l+r)*(r-l+1)/2;
        sum%=mod;
    }
    return sum%=mod;
}
void solve(){
  int n,m;
  cin>>n>>m;
  cout<<(calc(m)-calc(n-1)+mod)%mod;
}
signed main(){
    GG;
    int _t=1;
    //cin>>_t;
    while(_t--){ 
        solve();
    }
     
}