#include <bits/stdc++.h>
using namespace std;
const int N = 5010, M = 20010;
int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], tot;
int id[N], cnt,st[M];
int d[N];//度数
stack<int>s;
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

void tarjan(int u, int from)
{
    dfn[u] = low[u] = ++ tot;
    s.push(u);

    for (int i = h[u]; i!=-1; i = ne[i])
    {
        int j = e[i];
        if (!dfn[j])//j未遍历过
        {
            tarjan(j, i);//dfs(j)
            low[u] = min(low[u], low[j]);//用j更新u
            if (dfn[u] < low[j])//j到不了u
                st[i] = st[i ^ 1] = 1;
        }
        else if (i != (from ^ 1))
            low[u] = min(low[u], dfn[j]);
    }
    if (dfn[u] == low[u])
    {
        ++ cnt;
        int y;
        do {
            y = s.top();
            s.pop();
            id[y] = cnt;
        } while (y != u);
    }
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m -- )
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    tarjan(1, -1);//防止搜反向边 用一个from

    for (int i = 0; i < idx; i ++ )
        //如果边i是桥 在其所连的出边的点j所在强连通分量的度+1
        // 桥两边的双连通分量各+1
        if (st[i])
            d[id[e[i]]] ++ ;

    int ans = 0;
    for (int i = 1; i <= cnt; i ++ )
        if (d[i] == 1)//多少个度数为1的节点(强连通分量)
            ans ++ ;//需要加的边的数量

    cout << (ans + 1) / 2 << endl;

    return 0;
}
