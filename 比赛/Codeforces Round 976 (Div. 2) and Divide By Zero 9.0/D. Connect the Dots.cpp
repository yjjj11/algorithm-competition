#include <bits/stdc++.h>
using namespace std;
struct DSU {
    std::vector<int> fa, siz;
    DSU(int n) : fa(n + 1), siz(n + 1, 1) {
        std::iota(fa.begin(), fa.end(), 0);
    }
    inline int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    inline bool same(int x, int y) {
        return find(x) == find(y);
    }
    // true if x and y were not in the same set, false otherwise.
    inline bool merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return false;
        if (siz[fx] < siz[fy]) swap(fx, fy);//启发式
        fa[fy] = fx, siz[fx] += siz[fy], siz[fy] = 0;
        return true;
    }
    // x -> y, a.k.a let x be son of y (disable merge by rank).
    // inline bool directed_merge(int x, int y) {
    //     int fx = find(x), fy = find(y);
    //     if (fx == fy) return false;
    //     fa[fx] = fy, siz[fy] += siz[fx], siz[fx] = 0;
    //     return true;
    // }
};
int t, n, m, a, k, d;
inline void solve(void) {
    cin >> n >> m;
    vector<pair<int, int>> segs[11][11];
    for (int i = 1; i <= m; i++) {
        cin >> a >> d >> k;
        segs[d][a % d].push_back({a, a + k * d});//离线保存每一个操作并分类
    }
    DSU D(n);
    int ans = n;
    for (int i = 1; i <= 10; i++) {
        for (int rem = 0; rem < i; rem++) {//相同d值和相同余数的操作在首位==首尾相接的时候是可以合并的
            auto &seg = segs[i][rem];
            const int siz = seg.size();
            sort(seg.begin(), seg.end());
            for (int l = 0, r = 0; l < siz; l = r) {
                int L = seg[l].first, R = seg[l].second;
                while (r < siz && seg[r].first <= R) {
                    R = max(R, seg[r].second), r++;
                }//看当前这段一共可以吞并多少个区间，吞并完成后实现合并操作
                for (int j = L; j < R; j += i) {
                    ans -= D.merge(j, j + i);//合并一次，连通块的数量就减少1
                }
            }
        }
    }
    cout << ans << '\n';
}
inline void optimizeIO(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
}
int main(int argc, char const *argv[]) {
    optimizeIO(), cin >> t;
    while (t--) solve();
    return 0;
}