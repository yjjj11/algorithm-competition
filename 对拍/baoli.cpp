#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int a, b;
    cin>>a>>b;
    int ans = -1;
    for(int i=1;i<=4e10;i++){
        if(__gcd(a,i)!=1&&__gcd(b,i)!=1){
            ans=i;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
