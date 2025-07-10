#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define int long long
int e[N],ne[N],h[N],idx,w[N],hh[N];
int dfn[N],low[N],id[N],tot,cnt,st[N],d[N];
int  f[N],vis[N];
stack<int>s;
void add(int a,int b,int c,int h[]){
    e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
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
        }while(y!=u);
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    memset(h,-1,sizeof h);
    memset(hh,-1,sizeof hh);
    memset(f,0x3f,sizeof f);
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==b)continue;
        add(a,b,c,h);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=h[i];~j;j=ne[j]){
            int k=e[j];
            if(id[i]==id[k])continue;
            add(id[i],id[k],w[j],hh);
            // cout<<id[i]<<" "<<id[k]<<" "<<w[j]<<"\n";
        }
    }
    // for(int i=1;i<=n;i++)cout<<id[i]<<" ";
    // cout<<"\n";
    // cout<<cnt<<"\n";
    int be=id[1];
    queue<int>q;
    q.push(be),f[be]=0;
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int i=hh[u];~i;i=ne[i]){
            int j=e[i];
            f[j]=min(f[u]+w[i],f[j]);
            q.push(j);
        }
    }
    cout<<f[id[n]]<<endl;
}