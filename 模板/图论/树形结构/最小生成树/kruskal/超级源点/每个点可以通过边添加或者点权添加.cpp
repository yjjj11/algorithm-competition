#include<bits/stdc++.h>
#define N 310
using namespace std;
struct node{
    int from,to,dis;
}e[N*N];
int n,v,p[N][N];
int fa[N],tot,cnt,ans;
bool rule(const node &x,const node &y)//按边权从小到大排序
{
    return x.dis<y.dis;
}
int find(int x)//并查集基本操作
{
    if(fa[x]==x)
        return x;
    return fa[x]=find(fa[x]);
}
inline void merge(int x,int y)//并查集基本操作
{
    fa[find(y)]=find(x);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n+1;i++)//并查集初始化
        fa[i]=i;
    for(int i=1;i<=n;i++){
        scanf("%d",&v);
        e[++tot].from=n+1;//从"超级发电站"向该点连一条权值为v的边
        e[tot].to=i;
        e[tot].dis=v;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&p[i][j]);
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++){
            e[++tot].from=i;
            e[tot].to=j;
            e[tot].dis=p[i][j];
        }
    sort(e+1,e+1+tot,rule);
    for(int i=1;i<=tot;i++){//标准克鲁斯卡尔算法
        int u=e[i].from,v=e[i].to;
        if(find(u)!=find(v)){
            merge(u,v);
            ans+=e[i].dis;
        }
    }
    printf("%d\n",ans);
    return 0;
}

