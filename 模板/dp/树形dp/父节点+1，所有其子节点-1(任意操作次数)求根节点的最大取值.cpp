#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
vector<int> p[200005];
int a[200005], dp[200005];

int dfs(int u, int fa) {
    int minn = inf;
    for (auto j : p[u]) {
        if (j == fa) continue;
        int d = dfs(j, u);
        minn = min(minn, d);
    }
    if (minn == inf) {
        dp[u] = a[u];//叶子节点
        return dp[u];
    } else {
        if (minn <= a[u]) {
            dp[u] =minn;//如果子节点的最小值比自己节点的值药效==要小，那么当前节点就只能拥有minn的点数
            return dp[u];
        } else {//如果子节点的最小值比父节点的要大
            dp[u] = a[u] + (minn - a[u]) / 2;//父节点在被根节点吸收掉a[u]的情况下，还可以从子节点汲取(minn - a[u]) / 2的点数
            return dp[u];//因为子节点给父节点之后，父节点还要给父节点，而这两次操作子节点都会-1，
            //我们要始终保证在传递过程中子节点大于等于父节点，并且尽量增大父节点
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            p[i].clear();
        }
        for (int i = 2; i <= n; i++) {
            int x;
            cin >> x;
            p[x].push_back(i);
        }
        dfs(1, -1);//提高子节点的平均值
        int ans = a[1], minn = inf;
        for (auto j : p[1]) {
            minn = min(minn, dp[j]);
        }
        ans += minn;
        cout << ans << "\n";
    }
    return 0;
}
