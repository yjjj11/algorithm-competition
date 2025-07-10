#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define rep(i, a, n) for(int i = a; i <= n; i++)
#define per(i, a, n) for(int i = n; i >= a; i--)
typedef pair<int, int> PII;
const int mod = 1e9 + 7;
const int N = 9010;
int value[11];
int n, m;
int weight[N], w[N];
int b[N];
 
void solve() {
	int f[N] = {0};
	rep(i, 1, 10) cin >> value[i]; 
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) {
		cin >> weight[i];
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++)
		for (int j = weight[i]; j <= m; j++ )
			f[j] = max(f[j], f[j - weight[i]] + b[i]);
	int vv[N] = {0};
	rep(i, 1, m) {
		vv[i] = value[f[i] * 10 / i + (f[i] * 10 % i != 0)];
	}
	int dp[N] = {0};
	int maxx = 0;
	rep(i, 1, m) {
		for (int j = 0; i + j <= m; j++) {
			dp[i + j] = max(dp[i + j], dp[j] + i * vv[i]);
			maxx = max(maxx, dp[i + j]);
		}
	}
	cout << maxx << endl;
}
 
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
}