#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5,M=1e18;
#define x first
#define y second
#define PII pair<int,int>
int n,m,b,e[N],ne[N],h[N],idx,w[N],a[N],dist[N],dp[N],st[N];
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
void dijkstra(){
    for(int i=1;i<=n;i++)dist[i]=M,dp[i]=M;
    memset(st,0,sizeof st);
    dist[1]=0,dp[1]=a[1];
    // cout<<dp[1]<<"\n";
    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({0,1});
    while(q.size()){
        auto t=q.top();
        q.pop();
        int u=t.y;
        if(st[u])continue;
        st[u]=1;
        // cout<<u<<"\n";
        for(int i=h[u];i!=-1;i=ne[i]){
            int j=e[i],len=w[i];
            
            if(dist[j]>=dist[u]+len){
                dist[j]=dist[u]+len;
                q.push({dist[j],j});
            }
            int temp=max(a[j],dp[u]);
            dp[j]=min(dp[j],temp);
            
        }
    }
    if(dist[n]==M||dist[n]>b)cout<<"AFK";
    else{
        cout<<dp[n];
    }
}
signed main(){
    cin>>n>>m>>b;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
    }
    dijkstra();
}
