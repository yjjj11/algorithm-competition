#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T, n, q, k;
ll x[100005];
map<ll, ll> m;
signed main() {
	cin >> T;
	while(T--) {
		m.clear();
		cin >> n >> q;
		for(int i=1; i<=n; i++) cin >> x[i];
		for(int i=1; i<=n; i++) {
			m[(n-i)+(i-1)+(i-1)*(n-i)]++; //统计点i答案 
			if(i+1<=n) m[i*(n-i)]+=(x[i+1]-x[i]-1); //统计i与i+1之间答案 
		}
		for(int i=1; i<=q; i++) {
			cin >> k;
			cout << m[k] << " ";
		}
		cout << "\n";
	}
	return 0;
}