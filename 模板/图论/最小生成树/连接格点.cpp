#include <iostream>
#pragma GCC optimize(2)

#define x first
#define y second

using namespace std;
typedef pair<int, int> PII;

const int N = 1010, M = N * N;
int p[M], n, m;

int get(int x, int y) { return x * m + y; }

struct Edge 
{
    int u, v, w;
    bool operator <(const Edge& W) const {
        return w < W.w ;
    }
} edge[M];

int find(int x) 
{
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main() 
{
    scanf("%d%d", &m, &n);

    for (int i = 1; i <= m * m + n; i ++ ) p[i] = i;

    int x1, y1, x2, y2;
    while (~scanf("%d%d%d%d", &x1, &y1, &x2, &y2))
        p[find(get(x1, y1))] = find(get(x2, y2));

    int res = 0;
    for (int i = 1; i <= n; i ++ ) 
    {
        for (int j = 1; j < m; j ++ )
        {
            int a = find(get(j, i)), b = find(get(j + 1, i));
            if (a != b) p[a] = b, res ++ ;
        }
    }

    for (int i = 1; i < n; i ++ ) 
    {
        int a = find(get(1, i)), b = find(get(1, i + 1));
        if (a != b) p[a] = b, res += 2;
    }

    printf("%d\n", res);

    return 0;
}
