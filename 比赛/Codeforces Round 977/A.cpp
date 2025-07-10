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
        int n,a[N];
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n);
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans=(ans+a[i])/2;
        }
        cout<<ans<<"\n";
    }
}