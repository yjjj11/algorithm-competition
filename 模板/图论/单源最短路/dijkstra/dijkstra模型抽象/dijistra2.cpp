#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define x first
#define y second
map<PII,int>mpp;
const int N = 2e5 + 5, M = 1e18;
int ne[N * 100ll], h[N], idx, w[N], dis[N], n, m;
int e[N*100ll];
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
bool st[150010];
struct node{
    int num;
    int diss;
};
priority_queue<node>q;
bool operator<(const node &a,const node &b){
    return a.diss>b.diss;
}
int dijkstra(int u){
    memset(dis,0x3f,sizeof dis);
    q.push({u,0});
    dis[u]=0;
    while(!q.empty()){
        node t=q.top();
        q.pop();
        if(st[t.num])continue;
        st[t.num]=true;
        for(int i=h[t.num];i!=-1;i=ne[i]){
            int j=e[i];
            if(dis[j]>t.diss+w[i]){
                dis[j]=t.diss+w[i];
                q.push({j,dis[j]});
            }
        }
    }
    if(dis[n]==M)cout<<"-1";
    else cout<<dis[n];
}
signed main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    
    for(int i=0;i<m;i++){
        int a,b,s;
        cin>>a>>b>>s;
        add(a,b,s);
        
    }
   
    dijkstra(1);
}
