#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 998244353;

int t, n, a;
set<pair<int, int>> r;
map<int, bool> p; 

signed main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> t;
	while (t--) {
		r.clear();
		p.clear();
		cin >> n;
		int ans = n;
		for (int i = 1; i <= n; ++i) {
			cin >> a;
			int k = a - 1 + i;
			r.insert({k, k + i - 1});
		}
		p[n] = 1;
		for (auto i : r) {
			if (p[i.first] == 1) {
				ans = max(ans, i.second);
				p[i.second] = 1;
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}
