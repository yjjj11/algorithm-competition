#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin >> t;
    while(t--){
        int b,c,d;
        cin>>b>>c>>d;
        int a=b^d;
        if((a|b)-(a&c)==d){
            cout<<a;
        }
        else cout<<"\n";
    }
    return 0;
}