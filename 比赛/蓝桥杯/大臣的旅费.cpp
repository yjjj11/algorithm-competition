#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n;
struct edge
{
    int id,w;//定义每个节点的编号和去该点的距离
};
vector<edge> h[N];//用vector存储图
int dist[N];//存放离当前节点的最大距离
void dfs(int u,int father,int distance)
{
    dist[u]=distance;
    for(auto node:h[u])//遍历当前节点可以到达的节点
    {
        if(node.id!=father)//排除父节点防止返回
        {
            dfs(node.id,u,distance+node.w);
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        h[a].push_back({b,c});
        h[b].push_back({a,c});
    }
    dfs(1,-1,0);//可从任一点开始dfs，找到该点能到达的所有点
    int u=1;
    for(int i=1;i<=n;i++)
    {
        if(dist[i]>dist[u])
        {
            u=i;//找到与当前点距离最远的一个点（即树的直径的一个端点）
        }
    }
    dfs(u,-1,0);//再找到树的直径的端点能到达的所有点
    for(int i=1;i<=n;i++)
    {
        if(dist[i]>dist[u])
        {
            u=i;//找到最远的那个点，就找到了当前树的直径的另一个端点
        }
    }
    int s=dist[u];//树的直径
    printf("%lld",10*s+s*(s+1ll)/2);//可能爆int转成LL，根据题意推出路费和距离的关系
    return 0;
    
}