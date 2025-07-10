
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 2e5 + 5;

int x[N], y[N];
int h[N], e[N], ne[N], idx;
int f[N];

void add(int u, int v) {
    e[idx] = v, ne[idx] = h[u], h[u] = idx++;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int mx = 0, r = 0;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        set<int> st;
        while (m--) {
            int x;
            cin >> x;
            st.insert(x);
        }
        for (int j = 0; true; j++) {
            if (!st.count(j)) {
                x[i] = j;
                mx = max(mx, j);
                for (int k = j + 1; true; k++) {
                    if (!st.count(k)) {
                        y[i] = k;
                        r = max(r, k);
                        break;
                    }
                }
                break;
            }
        }
    }
    idx = 0;
    memset(h, -1, r + 1 << 2);
    for (int i = 0; i < n; i++) {
        add(x[i], y[i]);
    }
    memset(f, 0, r + 1 << 2);
    for (int i = r; i >= 0; i--) {
        f[i] = i;
        int cnt = 0;
        for (int j = h[i]; j != -1; j = ne[j]) {
            f[i] = max(f[i], f[e[j]]);
            cnt++;
        }
        if (cnt > 1) mx = max(mx, f[i]);
    }
    LL ret = max(0ll, (m - r) * (m + r + 1ll) / 2);
    r = min(r, m);
    for (int i = 0; i <= r; i++) {
        ret += max(mx, f[i]);
    }
    cout << ret << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
