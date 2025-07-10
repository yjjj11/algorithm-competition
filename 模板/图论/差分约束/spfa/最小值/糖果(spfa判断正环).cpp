#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

typedef long long LL;

const int N = 100010, M = 300010;
int n, m;
int h[N], e[M], w[M], ne[M], idx;
LL dist[N];
int cnt[N];//ͳ�Ƶ���ǰ���ܹ��ж���������
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++;
}

bool spfa()
{
    deque<int> q;
    q.push_back(0);
    st[0] = true;
    memset(dist,-0x3f,sizeof dist);
    dist[0] = 0;
    while(q.size())
    {
        int t = q.back();
        q.pop_back();
        st[t] = false;//����ջ�� ״̬=false
        for (int i = h[t]; i!=-1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] < dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n + 1) return false;//�и��� �޽�
                if (!st[j])
                {
                    q.push_back(j);
                    st[j] = true;
                }
            }
        }
    }
    return true;
}
//求所有点的最小值就要找最长路
int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m -- )
    {
        int x, a, b;
        cin >> x >> a >> b;
        if (x == 1) add(b, a, 0), add(a, b, 0);//A=B
        else if (x == 2) add(a, b, 1);//B>=A+1
        else if (x == 3) add(b, a, 0);//A>=B
        else if (x == 4) add(b, a, 1);//A>=B+1
        else add(a, b, 0);//B>=A
    }
    for (int i = 1; i <= n; i ++ ) add(0, i, 1);

    if (!spfa()) cout << "-1" << endl;
    else
    {
        LL res = 0;
        for (int i = 1; i <= n; i ++ ) res += dist[i];
        cout << res << endl;
    }
    return 0;
}
