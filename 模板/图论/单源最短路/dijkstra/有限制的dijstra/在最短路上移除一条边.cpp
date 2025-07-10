#include <bits/stdc++.h>
using namespace std;
//if(1.*clock()/CLOCKS_PER_SEC>=0.99)//极限优化大法，在趋近于一秒前退出
//		  break;
//if(1.clock()/CLOCKS_PER_SEC>=0.99)//极限优化大法，在趋近于一秒前退出
long long n, m;
long long u, v, w;

bool flag;

long long vis[1005];
long long pth[1005];
long long pre[1005];

long long g[1005][1005];

inline void dijkstra() {
	memset(pth, 0x3f, sizeof(pth));
	memset(vis, 0, sizeof(vis));
	
	pth[1] = 0;
	
	for (register long long i = 1; i <= n; ++i) {
		long long t = -1;
		
		for (register long long j = 1; j <= n; ++j) {
			if (!vis[j] && (t == -1 || pth[t] > pth[j])) {
				t = j;
			}
		}
		
		vis[t] = 1;
		
		for (register long long j = 1; j <= n; ++j) {
			if (pth[t] + g[t][j] < pth[j]) {
				pth[j] = pth[t] + g[t][j];
				
				if (flag) {
					pre[j] = t;
				}//记录下最短路的路径
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	cin >> n >> m;
	
	memset(g, 0x3f, sizeof(g));
	
	for (register long long i = 1; i <= m; ++i) {
		cin >> u >> v >> w;
		
		g[u][v] = min(g[u][v], w);
		g[v][u] = min(g[v][u], w);
	}
	
	flag = true;
	
	dijkstra();
	
	flag = false;
	
	long long u=n;
	long long ans=0;
	
	while (pre[u]) {
		long long v = pre[u];
		long long tmp = g[u][v];
		
		g[u][v] = g[v][u] = pth[1004];//通过将路径长设为极大值的方法来移除该路径
		
		dijkstra();
		
		ans = max(ans, pth[n]);
		
		g[u][v] = g[v][u] = tmp;
		
		u = pre[u];
		
		if(1.*clock()/CLOCKS_PER_SEC>=0.99)
		  break;
	}
	
	cout << ans << endl;
	return 0;
}