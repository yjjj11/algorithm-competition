#include<bits/stdc++.h>
#define maxn 500005
using namespace std;
int n,m,s; //点，次数，根节点 
//链式前向星
int cnt=0,head[maxn];
struct Edge{
	int u,v,next;
}edge[maxn<<1]; 
void add(int u,int v){
	edge[++cnt]=(Edge){u,v,head[u]};head[u]=cnt;
}
//建树
int depth[maxn],p[maxn][25];
void dfs(int u,int fa){
	p[u][0]=fa;
	depth[u]=depth[fa]+1;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].v;
		if(v==fa) continue; //防止套娃，无线循环
		dfs(v,u); 
	}
} 
int lca(int x,int y){
	if(depth[x]<depth[y]) swap(x,y);
	for(int j=24;j>=0;j--){
		if(depth[x]-(1<<j)>=depth[y]){
			x=p[x][j]; //往上走 
		}
	}
	//特判&&巧合
	if(x==y) return x;
	//现在x和y深度差不多，同时上升
	for(int j=24;j>=0;j--){
		if(p[x][j]!=p[y][j]){
			x=p[x][j]; y=p[y][j];
		}
	} 
	return p[x][0];
}
int main(){
	cin>>n>>m>>s;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;add(u,v);add(v,u);
	}
	dfs(s,0); //建树 
	//预处理 
	for(int j=1;(1<<j)<=n;j++){ //长度  2^j<=n 
		for(int i=1;i<=n;i++){
			p[i][j]=p[p[i][j-1]][j-1];
		}
	} 
	//输出答案&&LCA
	while(m--){
		int x,y;cin>>x>>y;
		cout<<lca(x,y)<<endl;
	} 
	return 0;
}
