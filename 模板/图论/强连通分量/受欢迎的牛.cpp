#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int e[N],ne[N],h[N],idx;
int low[N],dfn[N],cnt,st[N],scc[N],si[N],tot,d[N];
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
int main(){
    int n,m;
    cin>>n>>m;
    memset(h,-1,sizeof h);
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
    for(int i=1;i<=n;i++){
        
        for(int j=h[i];~j;j=ne[j]){
            int k=e[j];
            int a=scc[i],b=scc[k];
            if(a!=b)d[a]++;
        }
    }
    int ans=0,zero=0;
    for(int i=1;i<=cnt;i++){
        
        if(d[i]==0){
            zero++;
            if(zero>1){
                ans=0;
                break;
            }
            else ans+=si[i];
        }
    }
    cout<<ans<<"\n";
}