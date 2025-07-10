#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
#define pii pair<int,int>
int e[N],ne[N],h[N],idx;
int n,a[N],dp[N][10],ans=0;
void add(int a,int b){
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int dfs(int u,int fa){
    vector<int> s(10, 0);
	for(int k=h[u];~k;k=ne[k]){
		int v=e[k];
		if(v==fa) continue;
		dfs(v,u);
        for(int i=a[u];i<=9;i++){
            dp[u][i]+=dp[v][i-a[u]];//记录方案数而不是记录长度
            //已有的方案到u节点至少有两步，因此u内的方案数满足路径要求
        }
		for(int i=0;i<=9;i++){
			for(int j=0;j<=9-i-a[u];j++){
                ans+=dp[v][i]*s[j];//统计答案
            }
		}
        for(int i=0;i<10;i++)s[i]+=dp[v][i];//该父亲节点已有的长度为i的路径条数
	}
    for(int i=0;i<=9;i++)ans+=dp[u][i];
    dp[u][a[u]]++;
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
// 	cin>>t;
	while(t--){
        cin>>n;
        memset(h,-1,sizeof h);
        for(int i=1;i<=n;i++){
        	cin>>a[i];
        }
        for(int i=1;i<n;i++){
        	int x,y;
        	cin>>x>>y;
        	add(x,y),add(y,x);
        }
        dfs(1,0);
        cout<<ans<<"\n";
	}
}
