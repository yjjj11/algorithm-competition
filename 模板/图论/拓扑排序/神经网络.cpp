#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, p, e[N], ne[N], h[N], idx, w[N], u[N], d[N], cnt[N], c[N], maxn;

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void topsort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!d[i]) q.push(i);
    }
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        // cout<<t<<"\n";
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            // cout<<j<<" ";
            cnt[j] = cnt[t] + 1; // 更新层级
            maxn = max(maxn, cnt[j]); // 更新最大层级

            if (c[t] > 0) c[j] += w[i] * c[t]; // 更新神经状态
            // cout<<cnt[j]<<" "<<c[j]<<"\n";
            d[j]--;
            if (!d[j]) {
                q.push(j);
                c[j]-=u[j];
            }
        }
    }
}

signed main() {
    cin >> n >> p;
    memset(h, -1, sizeof h); // 初始化邻接表头
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> u[i];
    }
    for (int i = 1; i <= p; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        d[b]++;
    }
    topsort();
    bool found = false; // 用于检查是否有满足条件的节点
    for (int i = 1; i <= n; i++) {
        
        if (cnt[i] == maxn && c[i] > 0) {
            cout << i << " " << c[i] << "\n";
            found = true;
        }
    }
    if (!found) cout << "NULL\n"; // 如果没有满足条件的节点，输出NULL
}
