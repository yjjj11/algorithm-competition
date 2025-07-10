#include<bits/stdc++.h>
using namespace std;
int n,m,e,dis[2510];
struct node{
    int v;
    int w;
};
vector <node>g[2510];
queue<int>q;
bool vis[2510];
void spfa(int st,int ed){
    memset(dis,0x3f,sizeof(dis));
    q.push(st);
    dis[st]=0;
    // vis[st]=1;//vis[i]==1代表在队列中 
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        int k=g[u].size();
        for(int i=0;i<k;i++){
            int v,w;
            v=g[u][i].v;
            w=g[u][i].w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                // if(vis[v]==0){
                //     vis[v]=1;
                //     q.push(v);
                // }
                q.push(v);
            }
        }
    }
    cout<<dis[ed];
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    cin>>e;
    spfa(0,e);
    return 0;
} 
