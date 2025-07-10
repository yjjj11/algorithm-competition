#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define int long long
#define pii pair<int,int>
#define x first
#define y second
int n,q,e[N],ne[N],h[N],idx,sz[N],son[N],w[N],dep[N];
vector<pii>g[N];
int ans[N],pre[N],sum[N];//pre是前缀和
void add(int a,int b,int c){
    e[idx]=b,ne[idx]=h[a],h[a]=idx,w[idx]=c,idx++;
}
int dfs1(int u,int fa){
    sz[u]=1,dep[u]=dep[fa]+1;
    for(int i=h[u];~i;i=ne[i]){
        int v=e[i];
        if(v==fa)continue;
        int s=dfs1(v,u);
        if(s>sz[son[u]])son[u]=v;
        sz[u]+=s;
        pre[v]=pre[u]+w[i];
    }
    return sz[u];
}
void update(int u,int fa,int whether,int sonn){
    if(pre[u]>=sum[dep[u]])sum[dep[u]]=pre[u];
    for(int i=h[u];~i;i=ne[i]){
        int v=e[i];
        if(v==fa||v==sonn)continue;
        update(v, u, whether, sonn);
    }
}
void dsu(int u,int fa,int whether){ 
    for(int i=h[u];~i;i=ne[i]){
        int v=e[i];
        if(v==fa||v==son[u])continue;
        dsu(v,u,0);
    }
    if(son[u])dsu(son[u],u,1);
    update(u,fa,whether,son[u]);
    for(auto j:g[u]){
        int v=j.x,id=j.y;
        ans[id]=sum[dep[u]+v];
        if(ans[id]==0)ans[id]=-1;
    }
    if(whether==0)update(u,fa,0,0);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        cin>>n;
        memset(h,-1,sizeof h);
        idx = 0;
        for(int i=1;i<n;i++){
            int a,b,w;
            cin>>a>>b>>w;
            add(a,b,w),add(b,a,w);
        }
        dfs1(1,0);
        cin>>q;
        for(int i=1;i<=q;i++){
            int a,b;
            cin>>a>>b;
            g[a].push_back({b,i});
        }
        memset(sum, 0, sizeof sum);
        memset(ans, 0, sizeof ans);
        memset(pre, 0, sizeof pre);
        for(int i=1;i<=n;i++) g[i].clear();
        dsu(1,0,1);
        for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
    }
}
