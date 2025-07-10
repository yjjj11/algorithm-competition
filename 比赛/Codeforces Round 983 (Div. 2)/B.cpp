#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
#define pii pair<int,int>
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
	while(t--){
        int n,k;
        cin>>n>>k;
        if(n==1){
            cout<<"1\n"<<"1\n";
            continue;
        }
        if(n==k||k==1){
            cout<<"-1\n";
            continue;
        }
        int ans=0;
        if(k%2==1){
            cout<<"5\n";
            cout<<"1 "<<k-1<<" "<<k<<" "<<k+1<<" "<<k+2<<"\n";
        }
        else{
            cout<<"3\n";
            cout<<"1 "<<k<<" "<<k+1<<"\n";
        }
	}
}
