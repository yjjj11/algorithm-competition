#include<bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair<int,int>
#define pb push_back
#define fi first
#define se second
#define endl '\n'
map<int,int> mp;

/**/

const int N = 300010, mod = 1e9+7;
int T, n, m;
int a[N];
int mina[N][30], gcd[N][30];
vector<int> ans[N];
 
void st(){
	int t = log(n)/log(2);
	
	for(int j=1;j<=t;j++)
	{
		for(int i=1;i<=n-(1<<j)+1;i++)
		{
			mina[i][j] = min(mina[i][j-1], mina[i+(1<<(j-1))][j-1]);
			gcd[i][j] = __gcd(gcd[i][j-1], gcd[i+(1<<(j-1))][j-1]);
		}
	}
}

bool query(int l, int r)
{
	int t = log(r-l+1)/log(2);
	
	int minn = min(mina[l][t], mina[r-(1<<t)+1][t]);
	int gcdd = __gcd(gcd[l][t], gcd[r-(1<<t)+1][t]);
	
	return minn == gcdd;
}

bool check(int mid)
{
	int flag = 0;
	
	for(int i=1;i<=n-mid+1;i++)
	{
		if(query(i, i+mid-1)){
			flag = 1;
			ans[mid].pb(i);
		}
	}
	if(flag) return 1;
	return 0;
}

signed main(){
	cin >> n;
	for(int i=1;i<=n;i++) cin>>a[i], mina[i][0] = gcd[i][0] = a[i];
	
	st();
	
	int l = 0, r = n;
	while(l<r)
	{
		int mid = l+r+1>>1;
		if(check(mid)) l = mid;
		else r = mid-1;
	}
	
	cout << ans[l].size() << " " <<l-1<<endl;
	for(auto x:ans[l]) cout<<x<<" ";
	
	return 0;
}
