#include <bits/stdc++.h>
#define int long long
#define inf INT64_MAX
#define ull unsigned long long

using namespace std;

const int N = 6e5 + 9;
int d[N], k[N], sz[N], z[N];
//d：当前结点深度  k：保留的距离要减掉的结点数  sz：当前结点代表的子树大小  z：第二部分答案的差分数组
int mx[N];//当前结点最深深度
int dmx;

vector<int> g[N];

void dfs(int st, int pre)//st：当前结点  pre：父节点
{
	if(st != 1)d[st] = d[pre] + 1;
	dmx = max(dmx, d[st]);//求出整棵树的最深深度
	
	sz[st] = 1;
	
	if(g[st].size() == 1 && st != 1)
	{
		mx[st] = d[st];
	}
	 
	for(auto &i : g[st])
	{
		if(i == pre)continue;
		
		dfs(i, st);
		k[d[st]] += sz[i];//第一部分答案
		sz[st] += sz[i];
		mx[st] = max(mx[st], mx[i]);
	}
	
	if(st != 1)z[mx[st] + 1] ++;//给第二部分答案做贡献
}

void init(int n)
{
	for(int i = 1;i <= n + 10;i ++)
	{
		g[i].clear();
		k[i] = 0;
		sz[i] = 0;
		z[i] = 0;
		mx[i] = 0;
	}
	dmx = 0;
}

void solve()
{
	int n;cin >> n;
	
	init(n);
	
	for(int i = 1;i < n;i ++)
	{
		int u, v;cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	d[1] = 0;
	dfs(1, -1);
	
	for(int i = 1;i <= dmx;i ++)z[i] += z[i - 1];//差分数组前缀和求出第二部分的答案
	for(int i = 1;i <= dmx;i ++)k[i] += z[i];//两部分答案求和
	
	int ans = inf;
	
	for(int i = 1;i <= dmx;i ++)ans = min(ans, k[i]);
	
	cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int t = 1;cin >> t;
    while(t --)solve();

    return 0;
}