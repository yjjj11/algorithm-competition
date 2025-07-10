#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define db double
#define int long long
#define PII pair<int,int >
#define mem(a,b) memset(a,b,sizeof(a))
#define IOS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);

using namespace std;
const int mod = 1e9+7,inf = 1e18;
const int N = 2e5+10,M = 2010;

int T,n,m,k;
string va[N];
int siz[N],son[N],dep[N],acc[N][25],cnt = 22;
int sum[N];
int anw[N];

set<string > s[N];
vector<PII > v[N];
vector<int > e[N];

void get(int now,int p)
{
	siz[now] = 1;
	acc[now][0] = p;
	dep[now] = dep[p]+1;
	for(auto spot:e[now])
	{
		if(spot==p) continue;
		get(spot,now);
		siz[now] += siz[spot];
		if(siz[spot]>siz[son[now]]) son[now] = spot;
	}
}

void add(int now,int p,int value,int wson)
{
	sum[dep[now]] += value;
	for(auto spot:e[now])
	{
		if(spot==p||spot==wson) continue;
		add(spot,now,value,wson);
	}
}

void dfs(int now,int p,int del)
{
	for(auto spot:e[now])
	{
		if(spot==p||spot==son[now]) continue;
		dfs(spot,now,1);
	}
	if(son[now]) dfs(son[now],now,0);
	add(now,p,1,son[now]);
	for(auto t:v[now]) anw[t.se] = sum[dep[now]+t.fi]-1;
	if(del) add(now,p,-1,0);
}

int query(int now,int x)
{
	for(int i=cnt;i>=0;i--)
	{
		if(x>=1ll<<i)
		{
			x -= 1ll<<i;
			now = acc[now][i];
		}
	}
	return now;
}

signed main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		e[a].pb(i);
		acc[i][0] = a;
	}
	for(int i=1;i<=n;i++)
	{
		if(!acc[i][0]) get(i,0);
	}
	for(int i=1;i<=cnt;i++)
	{
		for(int j=1;j<=n;j++)
		acc[j][i] = acc[acc[j][i-1]][i-1];
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		int now = query(a,b);
		v[now].pb({b,i});
	}
	for(int i=1;i<=n;i++)
	{
		if(!acc[i][0]) dfs(i,0,1);
	}
	for(int i=1;i<=m;i++) cout<<anw[i]<<" ";
	return 0;
}
