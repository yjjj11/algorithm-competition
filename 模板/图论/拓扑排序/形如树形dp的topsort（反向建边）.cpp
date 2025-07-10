#include <queue>
#include <iostream>
using namespace std;
const int N = 20010;
int head[N], ver[N], nxt[N], tot;
int n, m;
int deg[N], a[N], cnt;
int salary[N];
void add(int x, int y) {
    ver[++tot] = y, nxt[tot] = head[x], head[x] = tot;
    deg[y]++;
}
void topsort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) 
        if (!deg[i]) {
            q.push(i);
            salary[i] = 100;
        }
    while (q.size()) {
        int x = q.front(); q.pop();
        a[++cnt] = x;
        for (int i = head[x]; i; i = nxt[i]) {
            int y = ver[i];
            if (--deg[y] == 0) {
                salary[y] = salary[x] + 1;
                q.push(y);
            }
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        add(y, x);
    }
    topsort();
    if (cnt < n) puts("Poor Xed");
    else {
        int res = 0;
        for (int i = 1; i <= cnt; i++) 
            res += salary[i];
        cout << res << endl;
    }
    return 0;
}
