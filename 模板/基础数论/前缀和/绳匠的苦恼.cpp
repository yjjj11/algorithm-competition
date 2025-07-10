#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,mod=1e9+7;
int n,q,a[N],s[N],ps[N];
signed main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i],s[i]=(s[i-1]+a[i])%mod;
    for(int i=1;i<=n;i++)ps[i]=(ps[i-1]+s[i])%mod;
    while(q--){
        int l,r,ans=0;
        cin>>l>>r;
        if((r-l)%2==0)ans=(((ps[r]-ps[(l+r)/2-1]+mod)%mod-ps[(l+r)/2-1]+mod)%mod+ps[max(0ll,l-2ll)])%mod;
        else{
            ans=(((ps[r]-ps[(l+r)/2]+mod)%mod-ps[(l+r)/2-1]+mod)%mod+ps[max(0ll,l-2ll)])%mod;
        }
        cout<<ans<<"\n";
    }
}