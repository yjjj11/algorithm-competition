#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
const int N=1e5,inf=1e9;
int inq[N],dis[N],cnt[N];
vector<pair<int,int> > G[N];
queue<int> Q;
int main()
{
	int n,p,u,v,w;
	cin>>n>>p;
	for(int i=1;i<=p;i++){
		cin>>u>>v>>w;
		G[v].push_back(mp(u,w));
	}
	for(int i=1;i<=n;i++) dis[i]=inf;
	for(int r=1;r<=n;r++){
	    if(dis[r]!=inf) continue;
	    dis[r]=0;
	inq[r]=1; Q.push(r); //这循环里面的前三行是把每一个连通块都进行求解，因为图不一定联通
	while(!Q.empty()){
		int now=Q.front(); inq[now]=0; Q.pop(); cnt[now]++;
		if(cnt[now]>=n*n) { puts("NO SOLUTION"); return 0; }//加入队列的次数如果太多可能就是出现负环了
		for(int i=0;i<G[now].size();i++)
			if(dis[G[now][i].first]>dis[now]+G[now][i].second){
				dis[G[now][i].first]=dis[now]+G[now][i].second;
				Q.push(G[now][i].first),inq[G[now][i].first]=1;
			}
	}
	}
	int sm=0;
	for(int i=1;i<=n;i++) sm=min(sm,dis[i]); 
	for(int i=1;i<=n;i++) cout<<dis[i]-sm<<' ';
	return 0;
}