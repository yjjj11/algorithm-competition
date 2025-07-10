#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
//第一种边n条<=1000 第2、3种边各10000条
const int N = 1010, M = 21010, INF = 0x3f3f3f3f;

int n, m1, m2;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
int q[N], cnt[N];
bool st[N];

void add(int a,int b,int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

bool spfa(int size)
{
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);
    memset(cnt,0,sizeof cnt);
    queue<int> q;
    for(int i=1;i<=size;i++)
    {
        q.push(i);
        dist[i] = 0;
        st[i] = true;
    }
    while(q.size())
    {
        int t=q.front();
        q.pop();
        st[t] = false;
        for(int i = h[t];~i;i=ne[i])
        {
            int j = e[i];
            if(dist[j]>dist[t]+w[i])//最短路
            {
                dist[j] = dist[t]+w[i];
                cnt[j] = cnt[t]+1;//这条路上点的个数
                if(cnt[j]>=n)return true;//负环--无解
                if(!st[j])//j不在队列中
                {
                    q.push(j);//j加入队列
                    st[j] = true;//标记j
                }

            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> m1 >> m2;
    memset(h,-1,sizeof h);

    for(int i=1;i<n;i++) add(i+1,i,0);//x[i] ≤ x[i+1]+0,奶牛排在队伍中的顺序和它们的编号是相同的，所以要有硬性的递增规定
    while(m1--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if(a>b) swap(a,b);//x[b] ≤ x[a] + L a→b
        add(a,b,c);
    }
    while(m2--)
    {
        int a,b,c;
        cin >> a >> b >> c;//x[a] ≤ x[b]-D  b→a
        if(a>b) swap(a,b);
        add(b,a,-c);
    }
    // 第一问 问这些约束有没有解 从超级源点出发==把所有点加入队列 看有没有负环
    if(spfa(n)) cout << -1;
    //如果不存在满足要求的方案，输出-1；
    // 第二问 只需要把第一个点加入队列 求第1个点到第n个点的最短距离
    else
    {
        spfa(1);
        //如果 1 号奶牛和 N 号奶牛间的距离可以任意大，输出-2；
        if(dist[n]==INF) cout << -2;
        //否则，输出在满足所有要求的情况下，1 号奶牛和 N 号奶牛间可能的最大距离。
        else cout << dist[n];
    }
    return 0;
}
