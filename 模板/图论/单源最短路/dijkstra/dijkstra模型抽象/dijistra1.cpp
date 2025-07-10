#include<bits/stdc++.h>
using namespace std;
int dis[105];
int vis[105];
int edge[105][105];
const int inf=1e9;
int vexnum;
void dijistra(int u,int v){
	for(int i=0;i<vexnum;i++){
		vis[i]=0;
		dis[i]=edge[u][i];//起点到各点的最短距离 
	}
	vis[u]=1;
	for(int i=0;i<vexnum-1;i++){
		int minn=inf;
		int pp;
		for(int j=0;j<vexnum;j++){
			if(vis[j]==0&&dis[j]<minn){
				minn=dis[j];
				pp=j;//找到此轮中所要走的方向，始终朝着最近的走 
			}
		}
	    vis[pp]=1; 
		for(int j=0;j<vexnum;j++){//更新起点到各个联通点之间的最短距离 
			if(vis[j]==0&&dis[pp]+edge[pp][j]<dis[j]){
				dis[j]=dis[pp]+edge[pp][j];
			}
		}
	}
	cout<<dis[v];
}
int main(){
	int n,m,p,u,v,w;
	cin>>n>>m;
	vexnum=n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)edge[i][j]=0;
			else edge[i][j]=inf;
		}
	}
	for(int j=0;j<m;j++){
		cin>>u>>v>>w;
		edge[u][v]=w;
	}
	cin>>p;
	dijistra(0,p);
	return 0;
}
