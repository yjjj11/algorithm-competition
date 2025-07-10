#include<iostream>
#include<cmath>
using namespace std;

const int N=100010;
int n,m,a[N];
int f[N][20];

void st(){
	int t = log(n)/log(2);
	
	for(int j=1;j<=t;j++)
		for(int i=1;i<=n-(1<<j)+1;i++)
		{
			gcd[i][j] = __gcd(gcd[i][j-1], gcd[i+(1<<(j-1))][j-1]);
		}
}

int query(int l, int r)
{
	int t = log(r-l+1)/log(2);
	
	return __gcd(gcd[l][t], gcd[r-(1<<t)+1][t]);
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	RMQ();
	
	while(m--){
		int x,y;cin>>x>>y;
		cout<<query(x,y)<<endl;
	}
	
	return 0;
} 
