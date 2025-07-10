//考虑一个对偶的建图方式,将每一个单词看作一条边,其开头两个字符和结尾两个字符为它两边的点.
//01分数规划，将边权设置为w[i]-mid,判断是否存在正环;
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 700, M = 100010;

int n;
int h[N], e[M], w[M], ne[M], idx;
double dist[N];
int q[N], cnt[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool check(double mid) {
    memset(st, 0, sizeof(st));
    memset(cnt, 0, sizeof(cnt));
    int hh = 0, tt = 0;
    for (int i = 0; i < 676; i++) {
        q[tt++] = i;
        st[i] = true;
    }
    int count = 0;
    while (hh != tt) {
        int t = q[hh++];
        if (hh == N) hh = 0;
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
             if (dist[j] < dist[t] + w[i] - mid) {
                 dist[j] = dist[t] + w[i] - mid;
                 cnt[j] = cnt[t] + 1;
                 if (++count > 10000) return true;
                 if (cnt[j] >= N) return true;
                 if (!st[j]) {
                     q[tt++] = j;
                     if (tt == N) tt = 0;
                     st[j] = true;
                 }
             }
        }
    }
    return false;
}

int main() {
    char str[1010];
    while (scanf("%d", &n)) {
        if (n == 0) break;
        memset(h, -1, sizeof(h));
        idx = 0;
        for (int i = 0; i < n; i++) {
            scanf("%s", str);
            int len = strlen(str);
            if (len >= 2) {
                int left = (str[0] - 'a') * 26 + str[1] - 'a',
                    right = (str[len - 2] - 'a') * 26 + str[len - 1] - 'a';
                add(left, right, len);
            }
        }
        if (!check(0)) puts("No solution");
        else {
            double l = 0, r = 1000;
            while (r - l > 1e-4) {
                double mid = (l + r) / 2;
                if (check(mid)) l = mid;
                else r = mid;
            }
            printf("%lf\n", r);
        }
    }
    return 0;
}
