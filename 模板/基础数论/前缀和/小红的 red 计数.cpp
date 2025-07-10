/*
前缀和 + 前缀和的前缀和
https://ac.nowcoder.com/acm/contest/91592/E
 
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int pre[N];	//前缀r的数量 
int suf[N];	//后缀d的数量
int ppre[N];	//pre的前缀和，只有str[i]=='e'时增加 
int psuf[N];	//suf的前缀和，只有str[i]=='e'时增加
int E[N];	//遍历i时前缀e的数量 
ll sum[N]; 	//未翻转时的red的数量 
int n;
string str;

void init()
{
	for(int i = 1; i <= n; i++)	//pre[]、E[] 
	{
		if(str[i] == 'e') E[i] = E[i - 1] + 1;
		else E[i] = E[i - 1];
		if(str[i] == 'r') pre[i] = pre[i - 1] + 1;
		else pre[i] = pre[i - 1];
	}
	for(int i = n; i >= 1; i--)	//suf[] 
		if(str[i] == 'd') suf[i] = suf[i + 1] + 1;
		else suf[i] = suf[i + 1];
	for(int i = 1; i <= n; i++)	//sum:未翻转时的red的数量 	
		if(str[i] == 'e') sum[i] = sum[i - 1] + pre[i] * suf[i];
		else sum[i] = sum[i - 1];	
	for(int i = 1; i <= n; i++)	//ppre[]、psuf[]
		if(str[i] == 'e')
		{
			ppre[i] = ppre[i - 1] + pre[i];	
			psuf[i] = psuf[i - 1] + suf[i] ;
		}
		else
		{
			ppre[i] = ppre[i - 1];
			psuf[i] = psuf[i - 1];
		}
}
void slove()	//O(1) 
{
	int l,r; cin>>l>>r;
	ll ans1 = sum[l - 1] + (sum[n] - sum[r]);	//1~l-1和r+1~n的e的贡献，即非反转区间的e的贡献 
	ll x = pre[l - 1] + pre[r],y = suf[r + 1] + suf[l];
	ll ans2 = x * y * (E[r] - E[l - 1]) - (x * (psuf[r] - psuf[l - 1]) + y * (ppre[r] - ppre[l - 1])) + (sum[r] - sum[l - 1]);
	ll ans = ans1 + ans2;
	cout<<ans<<endl;
}
int main()
{
	int t = 1; //cin>>t;
	cin>>n>>t;
	cin>>str; str = "*" + str;
	init();
	while(t--)
	{
		slove();
	}
	return 0;
}
