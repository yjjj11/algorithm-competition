#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1005, M = 5005;
int n, q[N * M], m, f[N], cnt[N];
int head[N], numE = 0;
double dis[N];
bool vis[N];
struct E{
    int next, v, w;
}e[M];
void add(int u, int v, int w) {
    e[++numE] = (E) { head[u], v, w };
    head[u] = numE;
}
bool inline check(double mid) {
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i++)
        vis[i] = true, dis[i] = cnt[i] = 0, q[++tt] = i;
    while(hh <= tt) {
        int u = q[hh++];
        vis[u] = false;
        for (int i = head[u]; i; i = e[i].next) {
            int v = e[i].v;
            double w = e[i].w * mid - f[u];
            if(dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if(cnt[v] >= n) return true;
                if(!vis[v]) q[++tt] = v;
            }
        }
    }
    return false;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", f + i);
    for (int i = 1, u, v, w; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
    }

    double l = 0, r = 1000, eps = 1e-4;
    while(r - l > eps) {
        double mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    printf("%.2lf\n", r);
    return 0;
}
