#include <iostream>
#include <cstring>
using namespace std;
const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N], dist[N];
//邻接矩阵存储所有边
//dist存储其他点到S的距离
bool st[N];

int prim() {
    //如果图不连通返回INF, 否则返回res
    memset(dist, INF, sizeof dist);
    int res = 0;

    for(int i = 0; i < n; i++) {
        int t = -1;
        for(int j = 1; j <= n; j++) 
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        //寻找离集合S最近的点        
        if(i && dist[t] == INF) return INF;
        //判断是否连通，有无最小生成树

        if(i) res += dist[t];
        //cout << i << ' ' << res << endl;
        st[t] = true;
        //更新最新S的权值和

        for(int j = 1; j <= n; j++) dist[j] = min(dist[j], g[t][j]);
    }

    return res;
}

int main() {
    cin >> n >> m;
    int u, v, w;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i ==j) g[i][j] = 0;
            else g[i][j] = INF;

    while(m--) {
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = min(g[u][v], w);
    }
    int t = prim();
  
    if(t == INF) puts("impossible");
    else cout << t << endl;
}
