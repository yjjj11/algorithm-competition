#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int n, m, k, e[N], ne[N], h[N], idx, broken[N], fa[N];
struct node {
    int u, v;
} a[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int find(int x) {
    if (x == fa[x]) return x;
    else return fa[x] = find(fa[x]); // 路径压缩
}

map<int, int> mp;

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof(h)); // 初始化邻接表头
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[i].u = u, a[i].v = v;
        add(u, v), add(v, u);
    }
    cin >> k;
    // cout << k << " ";
    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        broken[i] = x, mp[x] = 1;
    }
    int ans[N], cnt = 0;
    cnt = n - k;
    // cout<<cnt<<" ";
    for (int i = 1; i <= m; i++) {
        int u = a[i].u, v = a[i].v;
        if (mp[u] || mp[v]) continue;
        int fu = find(u), fv = find(v);
        if (fu == fv) continue;
        fa[fu] = fv;
        cnt--;
    }
    ans[k + 1] = cnt;
    for (int i = k; i >= 1; i--) {
        int x = broken[i];
        mp[x] = 0; // 修复节点
        cnt++;
        for (int j = h[x]; j != -1; j = ne[j]) {
            int v = e[j];
            if (mp[v] == 1) continue; // 跳过未修复的节点
            int fv = find(v),fu= find(x);
            if (fu == fv) continue;
            fa[fu] = fv;
            cnt--;
        }
        ans[i] = cnt;
    }
    for (int i = 1; i <= k + 1; i++) {
        cout << ans[i] << endl;
    }
}
