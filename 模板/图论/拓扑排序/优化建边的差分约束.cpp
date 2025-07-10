#include <iostream>
#include <cstring>

using namespace std;

const int N = 2010 , M = 1000010;

int n , m;
int e[M] , ne[M] , w[M] , h[N] , idx;
int dist[N];
bool st[N];
int q[N] , d[N];
int res;

void add(int a , int b , int c)
{
    e[idx] = b , ne[idx] = h[a] , w[idx] = c , h[a] = idx++;
    d[b]++;
}

void topsort()
{
    int hh = 0 , tt = -1;
    for(int i = 1 ; i <= n + m ; i++)//因为加入了虚拟点，所以点数是n+m
        if(!d[i])
        {
            q[++tt] = i;
            if(i <= n) dist[i] = 1;//普通节点的初始等级是1，虚拟节点的初始等级是0.
        }

    while(hh <= tt)
    {
        int t = q[hh++];
        int temp = (t > n);//如果是虚拟节点连向普通点边权是1，普通节点连向虚拟节点边权是0
        for(int i = h[t] ; ~i ; i = ne[i])
        {
            int j = e[i];
            if(--d[j] == 0)
                dist[j] = dist[t] + temp , q[++tt] = j;
        }
    }
}

int main()
{
    cin >> n >> m;

    memset(h , -1 , sizeof h);
    for(int i = 1 ; i <= m ; i++)
    {
        memset(st , 0 , sizeof st);
        int cnt;
        cin >> cnt;
        int start = n , end = 1;
        while(cnt--)
        {
            int stop;
            cin >> stop;
            start = min(start , stop);
            end = max(end , stop);
            st[stop] = true;
        }

        int ver = i + n;//建立虚拟源点
        for(int j = start ; j <= end;  j++)
            if(st[j]) add(ver , j , 1);
            else add(j , ver , 0) ;
    }

    topsort();

    for(int i = 1 ; i <= n ; i++) res = max(res , dist[i]);

    cout << res << endl;
    return 0;
}