#include<bits/stdc++.h>
using namespace std;

const int N = 20009, INF = 1e9;

struct node
{//node存放边 
    int to, w;
    //to表示路径终点，w表示路径权值
    bool operator <(const node &x) const
    {
        if(w == x.w) return to > x.to;
        else return w > x.w;
    }
};

bool v[N];//记录节点有没有被访问 
int d[N];//记录每一个节点到起点最短路
int cnt[N];//记录每个牧场有多少奶牛
int n;//奶牛个数
int p;//牧场个数
int m;//边的个数
int ans = INF;//答案
vector <node> vec[N];//存边
priority_queue <node> q;//优先队列 

void dijkstra(int x)
{
    for (int i = 1; i <= p; ++ i) d[i] = INF, v[i] = false;
    //一开始，所有边都不与起点连通 
    d[x] = 0;//起点到自己的距离为0 
    q.push((node){x, 0});//起点入队 
    while (!q.empty())
    {
        node e = q.top(), tmp; q.pop();
        v[e.to] = true;//这个点被方问过
        for (int i = 0; i < vec[e.to].size(); ++ i)
        {
            tmp = vec[e.to][i];
            if (v[tmp.to]) continue;
            if (d[tmp.to] > d[e.to] + tmp.w)
            {
                d[tmp.to] = d[e.to] + tmp.w;//松弛
                q.push((node) {tmp.to, d[tmp.to]});//入优先队列
            }   
        }
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> p >> m;
    while (n --)
    {
        int cow; cin >> cow;
        cnt[cow] ++;
    }

    for (int i = 1, u, v, w; i <= m; ++ i)
    {//u代表路径起点，v代表路径终点，w代表路径长度 
        cin >> u >> v >> w;
        vec[u].push_back((node) {v, w});//建边 
        vec[v].push_back((node) {u, w});//建反边
        //因为是无向图，建两条边 
    }

    for(int i = 1, sum;i <= p;++ i)
    {
        dijkstra(i); sum = 0;
        bool flag = true;//判断奶牛是否都能走到点 i
        for (int j = 1; j <= p; ++ j)
            if(cnt[j])//如果有奶牛
            {
                if (d[j] == INF)//如果有奶牛走不到牧场i
                {
                    flag = false;//一定不是答案
                    break;
                }
                sum += cnt[j] * d[j];//累加答案
            }
        if (flag) ans = min(ans, sum);
    }

    cout << ans << endl;

    return 0;
}
