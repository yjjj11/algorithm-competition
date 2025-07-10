#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int n;
int w[N];
int up[N], down[N];
//迭代加深，答案较小时可以用
bool dfs(int u, int sum_up, int sum_down, int max_depth) {
    if (sum_up + sum_down > max_depth) return false;
    if (u == n) return true;

    int k = 0;
    while (k < sum_up && up[k] >= w[u]) ++ k;
    int t = up[k];
    up[k] = w[u];
    if (k == sum_up && dfs(u + 1, sum_up + 1, sum_down, max_depth)) return true;
    else if (k < sum_up && dfs(u + 1, sum_up, sum_down, max_depth)) return true;
    up[k] = t;

    k = 0;
    while (k < sum_down && down[k] <= w[u]) ++ k;
    t = down[k];
    down[k] = w[u];
    if (k == sum_down && dfs(u + 1, sum_up, sum_down + 1, max_depth)) return true;
    else if (k < sum_down && dfs(u + 1, sum_up, sum_down, max_depth)) return true;
    down[k] = t;

    return false;
}

int main() {
    while (cin >> n, n) {
        for (int i = 0; i < n; ++i) cin >> w[i];
        int depth = 0;
        while (!dfs(0, 0, 0, depth)) ++ depth;//从小到大枚举答案，一旦可以直接输出
        cout << depth << endl;
    }
    return 0;
}
