#include <bits/stdc++.h>
using namespace std;
const int N=10000*3+100;
const int M=1100;
int tot,n,m,k,ver[N],Next[N],head[N],edge[N],dis[M][M];
bool vis[M];
queue<int> q;
void spfa(int s)
{
    memset(dis,0x3f,sizeof(dis));
    memset(vis,false,sizeof(vis));
    dis[s][0]=0;
    vis[s]=1;
    q.push(s);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        vis[x]=0;
        for (int i=head[x]; i ; i=Next[i])
        {
            int j=edge[i],z=ver[i],w=max(dis[x][0],z);
            if (dis[j][0]>w)
            {
                dis[j][0]=w;
                if(!vis[j])
                    q.push(j),vis[j]=1;
            }
            for(int p=1; p<=k; p++)
            {
                int w=min(dis[x][p-1],max(dis[x][p],z));
                if (dis[j][p]>w)
                {
                    dis[j][p]=w;
                    if(!vis[j])
                        q.push(j),vis[j]=1;
                }
            }
        }
    }
}
void add(int a,int b,int c)
{
    edge[++tot]=b;
    ver[tot]=c;
    Next[tot]=head[a];
    head[a]=tot;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=m; i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    spfa(1);
    int ans=1e9;
    for(int i=0; i<=k; i++)
        ans=min(ans,dis[n][i]);
    if (ans==1e9)
        printf("-1");
    else
        printf("%d",ans);
    return 0;
}
