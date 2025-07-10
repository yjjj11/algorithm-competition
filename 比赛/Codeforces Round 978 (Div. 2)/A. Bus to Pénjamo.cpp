#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,M=1e18;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,r,a[N],ans=0,cnt=0;
        cin>>n>>r;
        int now=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            ans+=a[i]/2;
            if(a[i]&1)cnt++;
        }
        if(cnt<=(r-ans)){
            ans*=2;
            ans+=cnt;
        }
        else{
            cnt-=r-ans;
            ans=ans*2+(r-ans);
            ans-=cnt;
        }
        cout<<ans<<"\n";
    }
}