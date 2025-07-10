#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010, M = 5010;
const double eps = 1e-4;

int n, m;
int w_ver[N];
int h[N], e[M], w_edg[M], ne[M], idx;
double dist[N];
int cnt[N], q[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w_edg[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
//spfa算法本身具有一个性质，就是在求解最短路的时候，是可以把点权和边权看做一个整体边权一起更新的，因此我们常常在一些spfa的图论问题中，把点权存入边权中进行计算。
//求图中是否存在正环，和求负环是一个对称问题，直接更改spfa算法中的不等号方向，转而变成求最长路算法中是否存在正环，即可办到！！！！！！！！！！
bool check(double limit) {
    memset(dist, 0, sizeof dist);
    memset(cnt, 0, sizeof cnt);
    memset(st, 0, sizeof st);

    int hh = 0, tt = 0;
    for (int i = 1; i <= n; ++i) {
        q[tt++] = i;
        st[i] = true;
    }

    while (tt != hh) {
        int t = q[hh++];
        if (hh == N) hh = 0;
        st[t] = false;

        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            //这里求是否存在正环，因此spfa从寻找“最短路”改为寻找“最长路”
            if (dist[j] < dist[t] + w_ver[t] - limit * w_edg[i]) {
                dist[j] = dist[t] + w_ver[t] - limit * w_edg[i];
                cnt[j] = cnt[t] + 1;

                if (cnt[j] >= n) return true;

                if (!st[j]) {
                    st[j] = true;
                    q[tt++] = j;
                    if (tt == N) tt = 0;
                }
            }
        }
    }
    return false;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &w_ver[i]);

    memset(h, -1, sizeof h);
    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    double l = 1, r = 1000;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    printf("%.2lf\n", l);
    return 0;
}

