#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("O3")
using namespace std;
int n,a[200005],f[200005][2];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],f[i][0]=LONG_LONG_MIN,f[i][1]=LONG_LONG_MAX;
	for(int i=1;i<=n;i++)
	{
		f[i][0]=max(max(f[i-1][0]+a[i],f[i-1][1]+a[i]),max(llabs(f[i-1][0]+a[i]),llabs(f[i-1][1]+a[i])));
		f[i][1]=min(min(f[i-1][0]+a[i],f[i-1][1]+a[i]),min(llabs(f[i-1][0]+a[i]),llabs(f[i-1][1]+a[i])));
		
	}
	cout<<f[n][0]<<"\n";
	return;
}
signed main()
{
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
