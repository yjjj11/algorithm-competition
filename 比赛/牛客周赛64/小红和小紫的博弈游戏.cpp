#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve(){
    int x,y,a,b;
    cin>>x>>y>>a>>b;
    if(min(x+b,y+a)&1){
        cout<<"kou\n";
    }else{
        cout<<"yukari\n";
    }
}
int main() {
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}