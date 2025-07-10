#include<bits/stdc++.h>
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;
std::vector<std::vector<ll> >dp;
std::vector<ll>a;
std::vector<int>b;
int T,n,m;
ll ans;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		a.resize(n+1);
		for(int i=1;i<=n;++i)
			scanf("%lld",&a[i]),a[i]+=a[i-1];
		b.resize(m+1);
		for(int i=1;i<=m;++i)
			scanf("%d",&b[i]);
		dp.clear();
		dp.resize(m+2,std::vector<ll>(n+2,inf));
		ans=inf;dp[1][1]=0;
		for(int j=1;j<=m;++j){
			for(int i=1,k;i<=n;++i){
				k=std::upper_bound(a.begin()+i,a.begin()+n+1,b[j]+a[i-1])-a.begin();
				if(k>i)dp[j][k]=std::min(dp[j][k],dp[j][i]+m-j);
				dp[j+1][i]=std::min(dp[j+1][i],dp[j][i]); 
			}
			ans=std::min(ans,dp[j][n+1]);
		}
		if(ans==inf)ans=-1;
		printf("%lld\n",ans);
	}
	return 0;
}