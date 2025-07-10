#include <iostream>
#include <cstring>
#include <queue>
//多起点到单终点可以选择反向建图，或者建立虚拟源点到各个起点
using namespace std;
typedef pair<int, int> PII;

const int N = 1010, M = 40010, INF = 0x3f3f3f3f;
int h[N], w[M], e[M], ne[M], idx;
int n, m, T, dist[N], st[N], stn;

void add(int a, int b, int c) 
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++ ;
}

void Dijkstra(int S) 
{
    memset(st, 0, sizeof st);
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<> > heap;
    dist[S] = 0, heap.push({0, S});

    while (heap.size()) 
    {
        auto t = heap.top().second; heap.pop();

        if (st[t]) continue ;
        st[t] = true ; 

        for (int i = h[t]; ~i; i = ne[i]) 
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) 
            {
                dist[j] = dist[t] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

int main() 
{
    while (~scanf("%d%d%d", &n, &m, &T))
    {
        vector<int> stops; idx = 0;

        memset(h, -1, sizeof h);

        while (m -- )
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w); //反向建图
        }

        int S = 0;
        scanf("%d", &stn);
        while (stn -- ) 
        {
            int x;
            scanf("%d", &x);
            add(S, x, 0);
        }

        Dijkstra(S);

        int res = dist[T];
        if (res == INF) puts("-1");
        else printf("%d\n", res);
    }

    return 0;
}
