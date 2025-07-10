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
        pre[v]=pre[u]+w[i];
        int s=dfs1(v,u);
        if(s>sz[son[u]])son[u]=v;
        sz[u]+=s;
    }
    return sz[u];
}
map<int,int>mp;
void update(int u,int fa,int sonn){
    if(pre[u]>mp[dep[u]])mp[dep[u]]=pre[u];
    for(int i=h[u];~i;i=ne[i]){
        int v=e[i];
        if(v==fa||v==sonn)continue;
        update(v, u, sonn);
    }
}
void dsu(int u,int fa,int whether){ 
    for(int i=h[u];~i;i=ne[i]){
        int v=e[i];
        if(v==fa||v==son[u])continue;
        dsu(v,u,0);
    }
    if(son[u])dsu(son[u],u,1);
    update(u,fa,son[u]);
    for(auto j:g[u]){
        int v=j.x,id=j.y;
        if(mp[dep[u]+v]==0)ans[id]=-1;
        else ans[id]=mp[dep[u]+v]-pre[u];
    }
    if(whether==0)update(u,fa,0),mp.clear();
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
        dsu(1,0,1);
        for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
    }
}
