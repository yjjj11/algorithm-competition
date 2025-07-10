#include<bits/stdc++.h>
using namespace std;
const int MAXN=2001; 
bool f[MAXN][MAXN]; 
int n;
int a,sum; 
int ans=0x7f7f; 
int main()
{
	cin>>n;
	f[0][0]=true; 
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		sum+=a; 
		for(int j=sum;j>=0;j--)
			for(int k=sum-j;k>=0;k--)
				{
					if(j>=a) f[j][k]=f[j][k] || f[j-a][k]; 
					if(k>=a) f[j][k]=f[j][k] || f[j][k-a];
				}
	}
	for(int i=0;i<sum;i++)
		for(int j=0;j<sum-i;j++)
		{
			if(f[i][j]) ans=min(max(i,max(j,sum-i-j)),ans);  
		}
	cout<<ans;
	
}
