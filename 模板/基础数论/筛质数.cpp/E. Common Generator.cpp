#include <bits/stdc++.h>
#define all(s) s.begin(), s.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int _N = 4e5 + 5;

int vis[_N], pr[_N], cnt = 0;
//用2当生成器可以产生除了奇数素数以外的所有数；
void init(int n) {
	vis[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) {
			pr[++cnt] = i;
		}
		for (int j = 1; j <= cnt && i * pr[j] <= n; j++) {
			vis[i * pr[j]] = pr[j];
			if (i % pr[j] == 0) continue;
		}//线性筛法求出每个数的最小因子；
	}
}

int T;

void solve() {
	int n; cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	int p = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[a[i]]) p = a[i];
	}
	if (!p) {
		cout << 2 << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == p) continue;
		if (vis[a[i]] == 0) {
			cout << -1 << '\n';
			return;
		}
		if (a[i] & 1) {
			if (a[i] - vis[a[i]] < 2 * p) {
				cout << -1 << '\n';
				return;
			}
		} else {
			if (a[i] < 2 * p) {
				cout << -1 << '\n';
				return;
			}
		}
	}
	cout << p << '\n';
	return;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	init(400000);
	cin >> T;
	while (T--) {
		solve();
	}
}