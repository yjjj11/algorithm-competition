#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int n, m, e[N], ne[N], h[N], a[N], idx, f[N][105];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int x) {
     for(int i=1;i<=m;i++) f[x][i]=a[x];
    for (int i = h[x]; ~i; i = ne[i]) {
        int son = e[i];
        dfs(son);
        for (int j = m; j >= 1; j--) {
            for(int k=0;k<=j-1;k++)
            {
                f[x][j]=max(f[x][j],f[x][j-k]+f[son][k]);
            }

        }
    }
}

int main() {
    cin >> n >> m;
    m += 1; 
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[0] = 0; 
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    memset(f, 0, sizeof f);
    dfs(0);
    cout << f[0][m] << "\n";
}
