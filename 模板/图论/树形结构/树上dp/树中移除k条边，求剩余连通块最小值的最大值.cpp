#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200010;
int d[N],root=0;
struct lsqxx{
	int t, nxt; 
}e[N << 2];
int num[N], cnt;
void addedge(int f, int t){
	e[++ cnt].t = t;
	e[cnt].nxt = num[f];
	num[f] = cnt;
}
void clear(int n){
	cnt = 0;
	for(int i = 1 ; i <= n ; i ++) num[i] = 0;
}

int k;
int ans = 0;
int dfs1(int p, int f, int x){
	int lst = 1;
	for(int i = num[p] ; i ; i = e[i].nxt){
		int t = e[i].t;
		if(t == f) continue;
		lst += dfs1(t, p, x);
	}
	if(lst >= x) ans ++, lst = 0;
	return lst;
}

bool ck(int x){
	ans = 0;
	dfs1(root, 0, x);
	if(ans >= k + 1) return true;
	return false;
}

void solve(){
	int n;
	cin >> n >> k;
	clear(n);
	for(int i = 1 ; i < n ; i ++){
		int f, t;
		cin >> f >> t;
		d[f]++,d[t]++;
		addedge(f, t);
		addedge(t, f);
	}
	for(int i=1;i<=n;i++){
		if(d[i]==1)root=i;
	}
	int l = 0, r = n;
	while(l < r){
		int mid = (l + r) >> 1;
		if(ck(mid)) l = mid + 1;
		else r = mid - 1;
	}
	if(! ck(l)) l --;
	cout << l << '\n';
}

signed main(){
	int t;
	cin >> t;
	while(t --)
	solve();

	return 0;
}
