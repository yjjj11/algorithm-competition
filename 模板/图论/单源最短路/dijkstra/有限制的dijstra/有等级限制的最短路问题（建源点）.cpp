#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
const int N = 150, M = 2e4;

int n, m;
int dist[N];
int Rank[N];  //����ÿ����Ŷ�Ӧ�ĵȼ�
int value[N]; //����ÿ�������Ʒ��Ҫ��Ǯ
int h[N], ne[M], e[M], w[M], idx;
bool st[N];

void add(int a, int b, int c) //��ʽǰ���ǽ�ͼ
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra(int l, int r)
{
    //�����Ƕ��Ż���Ͻ�˹������ģ��
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st); //����Ҫ����εϽ�˹������������ؼǵ�ÿ�γ�ʼ��
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    dist[1] = 0;
    while (heap.size())
    {
        int ver = heap.top().second;
        heap.pop();
        if (st[ver])
            continue;
        st[ver] = true;

        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            //�����ʱ����һ�������жϵ�ǰ��ĵȼ��Ƿ��������ķ�Χ��
            if (dist[j] > dist[ver] + w[i] && Rank[j] <= r && Rank[j] >= l)
            {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    //�ڼ����ʱ����ʵ�Ĵ�ֵΪ����õ�����·��+�õ����Ʒ��ֵ
    int res = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
        res = min(res, dist[i] + value[i]);
    return res;
}

int main()
{
    cin >> m >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> value[i] >> Rank[i] >> x;
        while (x--)
        {
            int b, c;
            cin >> b >> c;
            add(i, b, c); //����ͼ��ֻ�ܴӸߵȼ�->�͵ȼ�
        }
    }

    int res = 0x3f3f3f3f;

    for (int i = Rank[1]; i <= Rank[1] + m; i++)
        res = min(res, dijkstra(i - m, i));
    cout << res;
    return 0;
}
