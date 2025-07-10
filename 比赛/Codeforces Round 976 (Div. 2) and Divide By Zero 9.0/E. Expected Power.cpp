#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,inv=285700002;
int t,n,a[200005],p[200005],dp[2][1024];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		memset(dp,0,sizeof(dp)); 
		dp[0][0]=1;
		for(int i=1;i<=n;i++){
			scanf("%d",&p[i]);//把每个数字的值当成重量，每个数字的概率当作收益，用背包的形式来计算每个容量对应的概率，当遇到一个问题需要枚举
			//所有可能的情况时，可以考虑用背包的形式来计算
			for(int j=0;j<1024;j++)dp[i&1][j]=(1ll*dp[i&1^1][j^a[i]]*p[i]%mod*inv%mod+1ll*dp[i&1^1][j]*(10000-p[i])%mod*inv%mod)%mod;
            //用背包的形式来计算每个容量对应的概率，选与不选两种可能
		}
		int ans=0;
		for(int j=0;j<1024;j++)(ans+=1ll*j*j*dp[n&1][j]%mod)%=mod;//E=Σxi^2*Pi
		printf("%d\n",ans);
	}
}