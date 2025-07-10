#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=0;
        for(int i=1;i<=3*n;i++){
            ans-=2*i-1;
            if(abs(ans)>n){
                cout<<"Sakurako\n";
                break;
            }
            i++;
            ans+=2*i-1;
            if(abs(ans)>n){
                cout<<"Kosuke\n";
                break;
            }
        }
    }
}