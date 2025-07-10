#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
signed main(){
	int m,n,a[N],b[N];
	cin>>m>>n;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int j=1;j<=n;j++)cin>>b[j];
	priority_queue<int,vector<int>,greater<int>> qq;//根小
	priority_queue<int,vector<int>,less<int>> qw;//根大
	int p=0;
	for(int i=1;i<=n;i++){
		while(p<b[i]){
			p++;
			qw.push(a[p]);
			if(qw.size()>i)qq.push(qw.top()),qw.pop();
		}
		cout<<qw.top()<<"\n";
		qw.push(qq.top());
		qq.pop();
	}
}
