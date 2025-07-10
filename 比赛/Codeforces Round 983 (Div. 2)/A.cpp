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
		int n,c1=0,c0=0;
		cin>>n;
        for(int i=1;i<=2*n;i++){
            int x;
            cin>>x;
            if(x==1)c1++;
            else c0++;
        }
        cout<<c1%2<<" "<<min(c0,c1)<<"\n";
	}
}
