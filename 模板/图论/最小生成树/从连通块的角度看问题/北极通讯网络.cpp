#include <cmath>
#include <iostream>
#include <algorithm>
//题目的要求即是: 找到满足连通块个数不超过k个的最小的d
//按照边权递增的顺序, 当把两个不联通的顶点联通时, 相当于在图中减少了一个连通块. 在连通块恰好减少到k时, 对应的边权因为有递增的保证, 所以是满足条件的最小边权.
#define x first
#define y second

using namespace std;

typedef pair<int, int> pii;

const int N = 510, M = N * N / 2;

int n, m, k;
int p[N]; 
pii points[N];
struct Edge
{
    int u, v;
    double w;
    bool operator< (const Edge &edge) const
    {
        return w < edge.w;
    }
}e[M];

double get_dist(const pii &p1, const pii &p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

int find(int x)
{
    return x == p[x] ? x : p[x] = find(p[x]);
}

double kruskal()
{
    for( int i = 1; i <= n; i ++ )  p[i] = i; //初始化并查集
    sort(e, e + m);
    int cnt = n; //初始连通块个数
    double res = 0; //初始边权 
    for( int i = 0; i < m; i ++ )
    {

        if( cnt <= k )  break; //找到最终解 这样写的好处是不用考虑k = 0的情况

        int u = find(e[i].u), v = find(e[i].v); 
        double w = e[i].w;
        if( u != v )
        {
            p[u] = v;
            cnt --;
            res = w;
        }
    }
    return res;
}

int main()
{
    cin >> n >> k;
    for( int i = 1; i <= n; i ++ )
        cin >> points[i].x >> points[i].y;
    for( int i = 1; i <= n; i ++ )
        for( int j = i + 1; j <= n; j ++ )
        {
            e[m ++] = {i, j, get_dist(points[i], points[j])};
        }

    printf("%.2lf\n", kruskal());

    return 0;
}