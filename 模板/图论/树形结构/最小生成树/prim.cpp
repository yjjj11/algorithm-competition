#include<bits/stdc++.h>
using namespace std;
int dis[105];
int vis[105];
int edge[105][105];
const int inf=1e9;
int n,u,v,w,m;
void prim(){
	for(int i=1;i<=n;i++){
		vis[i]=0;
		dis[i]=edge[1][i];//��㵽�������̾��� 
	}
	vis[1]=1;
	int cnt=1,sum=0;
	while(cnt<n){
		int minn=inf;
		int pp;
		for(int j=1;j<=n;j++){
			if(vis[j]==0&&dis[j]<minn){
				minn=dis[j];
				pp=j;//�ҵ���������Ҫ�ߵķ���ʼ�ճ���������� 
			}
		}
	    vis[pp]=1; 
	    sum+=minn;
		for(int j=1;j<=n;j++){//�����¼ӽ����ıߵ�Ȩֵ�����俴����㵽�µ���ͨ��ľ���
			if(vis[j]==0&&edge[pp][j]<dis[j]){
				dis[j]=edge[pp][j];
			}
		}
		cnt++;
	}
	cout<<sum<<"\n";
}
int main(){
	while(cin>>n){
	    if(n==0)return 0;
	    m=n*(n-1)/2;
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=n;j++){
    			if(i==j)edge[i][j]=0;
    			else edge[i][j]=inf;
    		}
    	}
    	for(int j=0;j<m;j++){
    		cin>>u>>v>>w;
    		edge[u][v]=w;
    		edge[v][u]=w;
    	}
    	prim();
	}
	return 0;
}
