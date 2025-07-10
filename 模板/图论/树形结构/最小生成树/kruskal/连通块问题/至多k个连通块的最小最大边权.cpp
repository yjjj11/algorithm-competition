#include <cmath>
#include <iostream>
#include <algorithm>

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
    for( int i = 1; i <= n; i ++ )  p[i] = i; //��ʼ�����鼯
    sort(e, e + m);
    int cnt = n; //��ʼ��ͨ�����
    double res = 0; //��ʼ��Ȩ 
    for( int i = 0; i < m; i ++ )
    {

        if( cnt <= k )  break; //�ҵ����ս� ����д�ĺô��ǲ��ÿ���k = 0�����

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
