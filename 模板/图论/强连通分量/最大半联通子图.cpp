#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int e[N],ne[N],h[N],idx;
int low[N],dfn[N],cnt,st[N],scc[N],si[N],tot,hs[N];
int f[N],g[N];
stack<int>s;
////最大半联通分量就是在强连通分量的拓扑图中找到节点数最大的一条链
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void add1(int a,int b){
    e[idx]=b,ne[idx]=hs[a],hs[a]=idx++;
}
void tarjan(int u){
    dfn[u]=low[u]=++tot;
    s.push(u),st[u]=1;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(!dfn[j]){
            tarjan(j);
            low[u]=min(low[u],low[j]);
        }
        else if(st[j])low[u]=min(low[u],dfn[j]);
    }
    if(dfn[u]==low[u]){
        ++cnt;
        int y;
        do{
            y=s.top();
            s.pop();
            st[y]=0;
            scc[y]=cnt;
            si[cnt]++;//记录每个强连通分量的大小
        }while(u!=y);
    }
}
signed main(){
    int n,m,x;
    cin>>n>>m>>x;
    memset(h,-1,sizeof h);
    memset(hs,-1,sizeof hs);
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    map<int,int>mp;
    for(int i=1;i<=n;i++){
        
        for(int j=h[i];~j;j=ne[j]){
            int k=e[j];
            int a=scc[i],b=scc[k];
            if(a!=b){
                int x=a*N+b;
                if(mp[x])continue;
                mp[x]=1;
                add1(a,b);//在强连通分量之间架起路径
            }
        }
    }
    //处理出每个强连通分量后自动满足拓扑序，编号越大拓扑序越靠前
    for(int i=cnt;i>=1;i--){
        if(!f[i]){
            f[i]=si[i],g[i]=1;//处理起点
        }
        for(int j=hs[i];~j;j=ne[j]){
            int k=e[j];
            if(f[k]<f[i]+si[k]){
                f[k]=f[i]+si[k];
                g[k]=g[i];
            }
            else if(f[k]==f[i]+si[k]){
                g[k]=(g[i]+g[k])%x;
            }
        }
    }
    int ans=0,maxn=0;
    for(int i=1;i<=cnt;i++){
            if(f[i]>maxn){
                maxn=f[i];
                ans=g[i];
            }
            else if(f[i]==maxn){
                ans=(ans+g[i])%x;
            }
    }    
    cout<<maxn<<"\n"<<ans<<"\n";
}