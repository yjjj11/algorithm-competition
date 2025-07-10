#include<bits/stdc++.h>
#define ll long long 
using namespace std;
/*快读省了*/
ll t, n, a[200100], ans;

int main() {
	cin>>t;
	while (t--) {
		ans = 2e18;
		cin>>n;
		for (int i = 1; i <= n; i++) 
			cin>>a[i];
		sort(a+1, a+n+1); // 排序
		for (int i = 2; i <= n; i++) { // 枚举最大值
			ll l = 1, r = i;
			while (l < r) { // 二分最小值
				ll mid = (l + r) >> 1;
				if (a[mid] + a[mid+1] > a[i]) {
					r = mid;
				} else l = mid + 1;
			}
			ll res = n - i + r - 1;
			ans = min(ans, res);
		}
		cout << ans << "\n";
	}
	return 0;// 完结撒花 ！
}