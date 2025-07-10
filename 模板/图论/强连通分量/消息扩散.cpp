#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define int long long
int e[N],ne[N],h[N],idx;
int dfn[N],low[N],id[N],tot,cnt,st[N],d[N];
stack<int>s;
void add(int a,int b){
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
        }while(y!=u);
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    memset(h,-1,sizeof h);
    while(m--){
        int a,b;
        cin>>a>>b;
        if(a==b)continue;
        add(a,b);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=h[i];~j;j=ne[j]){
            int k=e[j];
            if(id[i]==id[k])continue;
            d[id[k]]++;
        }
    }
    cout<<cnt<<"\n";
    int ans=0;
    for(int i=1;i<=cnt;i++){
        if(d[i]==0)ans++;
    }
    cout<<ans<<endl;
}