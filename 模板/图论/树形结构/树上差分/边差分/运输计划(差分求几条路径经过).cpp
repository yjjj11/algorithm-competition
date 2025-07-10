#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, m, e[N], ne[N], h[N], idx, w[N], ll[N], rr[N], cc[N];
int dis[N], fa[N][20], dep[N];
int l[N], r[N], len[N], maxn = 0, c[N], lc[N];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void dfs(int u, int f) {
    fa[u][0] = f, dep[u] = dep[f] + 1;
    for (int i = 1; i < 20; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j == f) continue;
        dis[j] = dis[u] + w[i];
        dfs(j, u);
    }
}

void dfs1(int u, int f) {
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j == f) continue;
        dfs1(j, u);
        c[u] += c[j];
    }
}

int LCA(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    for (int i = 19; i >= 0; i--) {
        if (dep[fa[a][i]] >= dep[b]) a = fa[a][i];
    }
    if (a == b) return a;
    for (int i = 19; i >= 0; i--) {
        if (fa[a][i] != fa[b][i]) {
            a = fa[a][i], b = fa[b][i];
        }
    }
    return fa[a][0];
}

bool check(int x) {
    memset(c, 0, sizeof c);
    int cnt = 0, ma = 0;
    for (int i = 1; i <= m; i++) {
        if (len[i] <= x) continue;
        c[l[i]]++, c[r[i]]++, c[lc[i]] -= 2;
        cnt++; // 比当前x大的边有几条
    }
    dfs1(1, 0);
    for (int i = 1; i <= n; i++) {
        if (c[rr[i]] == cnt) ma = max(ma, cc[i]);
    } // rr[i]保存的是该条边指向的儿子，每条边下放到儿子，若儿子经过cnt次，则代表这条边经过cnt次，该条边就可以试着清除掉，我们要保存类似边的最大值
    if (maxn - ma <= x) return true; // 如果最长路径减去最长边小于x，那么此长度是满足的
    return false;
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 1; i < n; i++) { // 注意这里是 i < n，因为树有 n-1 条边
        int a, b, c;
        cin >> a >> b >> c;
        ll[i] = a, rr[i] = b, cc[i] = c;
        add(a, b, c);
        add(b, a, c); // 无向图需要添加双向边
    }
    dfs(1, 0);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        l[i] = a, r[i] = b;
        int lca = LCA(a, b);
        lc[i] = lca;
        len[i] = dis[a] + dis[b] - 2 * dis[lca];
        maxn = max(maxn, len[i]);
    }
    int l = 0, r = maxn;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << "\n";
}
