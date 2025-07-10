#include<bits/stdc++.h>
using namespace std;
int n,m,d;//点 边 终点
int tot,head[10001];
int vis[1001][1001];//如题解 
double dis[1001][1001];//如题解 
struct Node{
	int to,v,s;//点 限速 路程
	int next; 
}t[100001]; 
struct Nodee{
	int x,v;
}from[1001][1001];
void add(int from,int to,int v,int s){
	tot++;
	t[tot].to=to;
	t[tot].v=v;
	t[tot].s=s;
	t[tot].next=head[from];
	head[from]=tot;
}
void out(int x,int v){//输出递归 x为点 v为速度(别把v当做点) 
	if(x==1) return;
	out(from[x][v].x,from[x][v].v);
	printf("%d ",x-1);//在输入时+1了 
}
void dj(){
	priority_queue<pair<double,pair<int,int> > >p;//时间,点,速度 
	p.push(make_pair(0,make_pair(1,70)));
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=1000;j++){
			dis[i][j]=1e9+1;
		}
	} 
	dis[1][70]=0;
	vis[1][70]=1;
	while(!p.empty()){
		int x=p.top().second.first;
		int vs=p.top().second.second;
		vis[x][vs]=0;
		p.pop();
		for(int i=head[x];i;i=t[i].next){//如题解 
			int y=t[i].to;
			int n_v=t[i].v;
			if(t[i].v){//有速度 
				if(dis[y][n_v]>dis[x][vs]+(double)t[i].s/(double)n_v){
					dis[y][n_v]=dis[x][vs]+(double)t[i].s/(double)n_v;
//					printf("from %d  to %d\n",x-1,y-1);
					from[y][n_v]={x,vs};
					if(vis[y][n_v]) continue;
					vis[y][n_v]=1;
					p.push(make_pair(-dis[y][n_v],make_pair(y,n_v)));
				
				}
				continue;
			}
			if(!t[i].v){//无速度 
				n_v=vs;//照原来速度跑
				if(dis[y][n_v]>dis[x][vs]+(double)t[i].s/(double)n_v){
					dis[y][n_v]=dis[x][vs]+(double)t[i].s/(double)n_v;
//					printf("from %d  to %d\n",x-1,y-1);	
					from[y][n_v]={x,vs};
					if(vis[y][n_v]) continue;
					vis[y][n_v]=1;
					p.push(make_pair(-dis[y][n_v],make_pair(y,n_v)));
				} 
				continue;
			}
		}
	}
	int min_=0;
	dis[d][min_]=1e9+100;
	for(int i=1;i<=1000;i++){
		if(dis[d][min_]>=dis[d][i]&&dis[d][i]!=1e9+1) min_=i;
	}
//	printf("%lf\n",dis[d][min_]);
	printf("0 ");
	out(d,min_);
	printf("\n");
}

int read(){
	int f1=0,f2=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f2=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		f1=(f1<<1)+(f1<<3)+(ch^48);
		ch=getchar();
	}
	return f1*f2;
}
int main(){
	n=read(),m=read(),d=read();
	d++;
	for(int i=1;i<=m;i++){
		int A=read(),S=read(),D=read(),F=read();
		A++,S++;
		add(A,S,D,F);
//		add(S,A,D,F);	
	}
	dj();
	return 0;
}
