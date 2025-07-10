#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=1e9;
// #define int long long
int e[N],ne[N],h[N],idx,w[N],hh[N];
int dfn[N],low[N],id[N],tot,cnt,st[N],si[N];
int  f[N],a[N],d[N],ar[N],vis[N];
stack<int>s;
vector<int>b[N];
void add(int a,int b,int h[]){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void tarjan(int u){
    dfn[u]=low[u]=++tot;
    s.push(u),st[u]=1;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(!dfn[j]){
            tarjan(j);
            low[u]=min(low[u],low[j]);
        }else if(st[j]){
            low[u]=min(low[u],dfn[j]);
        }
    }
    if(dfn[u]==low[u]){
        cnt++;
        int y;
        do{
            y=s.top();
            s.pop();
            st[y]=0;
            id[y]=cnt;
            b[cnt].push_back(y);
        }while(y!=u);
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,r;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        a[x]=y;
    }
    cin>>r;
    memset(h,-1,sizeof h);
    memset(hh,-1,sizeof hh);
    for(int i=1;i<=n;i++)ar[i]=M;
    // memset(f,0x3f,sizeof f);
    while(r--){
        int a,b;
        cin>>a>>b;
        if(a==b)continue;
        add(a,b,h);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=h[i];~j;j=ne[j]){
            int k=e[j];
            if(id[i]==id[k])continue;
            add(id[i],id[k],hh);
            d[id[k]]++;
            // cout<<id[i]<<" "<<id[k]<<" "<<w[j]<<"\n";
        }
    }
    // for(int i=1;i<=n;i++)cout<<id[i]<<" ";
    // cout<<"\n";
    // cout<<cnt<<"\n";
    for(int i=1;i<=n;i++){
        int fa=id[i];
        if(a[i]){
            ar[fa]=min(ar[fa],a[i]);
            int len=b[fa].size();
            for(int j=0;j<len;j++){
                int x=b[fa][j];
                vis[x]=1;
            }
        }
    }
    // for(int i=1;i<=cnt;i++){
    //     cout<<ar[i]<<" ";
    // }
    // cout<<"\n";
    int ans=1e9,cost=0;
    queue<int>q;
    tot=0;
    for(int i=1;i<=cnt;i++){
        if(!d[i]){
            tot++;//一共有几个头
            if(ar[i]!=M)cost+=ar[i],q.push(i);//入口被收买了，花费ar[i]
        }
    }
    memset(st,0,sizeof st);
    int len=q.size();
    if(len==tot){
        cout<<"YES\n";
        cout<<cost<<"\n";
        return 0;
    }
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int i=hh[u];~i;i=ne[i]){
            int j=e[i];
            if(st[j])continue;
            st[j]=1;
            int len=b[j].size();
            for(int k=0;k<len;k++){
                int x=b[j][k];
                vis[x]=1;
            }
            q.push(j);//入队
        }
    }
    for(int i=1;i<=n;i++){
        if(!vis[i])ans=min(ans,i);//出口没有被收买，花费ar[id[i]]
    }
    cout<<"NO\n";
    cout<<ans<<"\n";
}