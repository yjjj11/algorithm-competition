#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int e[N],ne[N],h[N],idx;
int low[N],dfn[N],cnt,st[N],scc[N],si[N],tot;
int din[N],dout[N];
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
    int n;
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        int x;
        while(cin>>x){
            if(!x)break;
            add(i,x);
        }
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
            if(a!=b)din[b]++,dout[a]++;
        }
    }
    int ans1=0,ans2=0;
    for(int i=1;i<=cnt;i++){
        if(din[i]==0)ans1++;
        if(dout[i]==0)ans2++;
    }
    cout<<ans1<<"\n";
    if(cnt==1)cout<<"0\n";
    else cout<<max(ans1,ans2)<<"\n";
}