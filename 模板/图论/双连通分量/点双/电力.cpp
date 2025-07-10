#include<bits/stdc++.h>
using namespace std;
const int N=10010,M=30010;
int h[N],e[M],ne[M],idx;
int dfn[N],low[N],timestamp;
int ans,root;
int n,m;
void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void tarjan(int u)
{
    dfn[u]=low[u]=++timestamp;

    int cnt=0;//统计去掉u点剩下的连通块的数量。
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(!dfn[j])
        {
            tarjan(j);
            low[u]=min(low[u],low[j]);
            if(low[j]>=dfn[u]) cnt++;
        }
        else low[u]=min(low[u],dfn[j]);
    }
    if(u!=root&&cnt) cnt++;
    ans=max(ans,cnt);
}
int main()
{
    while(cin>>n>>m,n||m)
    {
        memset(h,-1,sizeof h);
        memset(dfn,0,sizeof dfn);
        idx=timestamp=0;

        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            add(a,b),add(b,a);
        }

        ans=0;
        int cnt=0;
        //点的编号从0开始
        for(root=0;root<n;root++)
            if(!dfn[root])
            {
                cnt++;
                tarjan(root);
            }

        cout<<cnt-1+ans<<endl;
    }
    return 0;
}
