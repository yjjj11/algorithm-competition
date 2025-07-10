#include <iostream>
#include <algorithm>

using namespace std;

const int N = 6010;

struct Edge{
    int u , v , w;
    bool operator < (const Edge &W) const{
        return w < W.w;
    }
}edge[N];

int n;
int f[N];
int cnt[N];

int find(int x)
{
    return f[x] = (f[x] == x ? x : find(f[x]));
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n;

        for(int i = 1 ; i <= n ; i++)   f[i] = i , cnt[i] = 1;

        for(int i = 0 ; i < n - 1; i++)
        {
            int u , v , w;
            cin >> u >> v >> w;
            edge[i] = {u , v , w};
        }

        sort(edge , edge + n - 1);

        int res = 0;
        for(int i = 0 ; i < n - 1 ; i ++)
        {
            auto e = edge[i];
            int u = find(e.u) , v = find(e.v) , w = e.w;
            if(u != v)
            {
                res += (cnt[u] * cnt[v] - 1) * (w + 1);//两个连通块在合并的时候要求两块间所有点对都连上一条边，除了已给定的那条边，边权为w+1
                f[u] = v;
                cnt[v] += cnt[u];
            }
        }

        cout << res << endl;
    }
    return 0;
}
