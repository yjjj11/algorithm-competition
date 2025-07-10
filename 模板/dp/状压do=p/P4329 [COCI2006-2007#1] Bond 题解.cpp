#include<bits/stdc++.h>
using namespace std;
int n;
double a[25][25];
double f[(1<<20)+5];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%lf",&a[i][j]),a[i][j]*=0.01;
	int tot=1<<n;
	f[0]=1;//初始状态
	for(int i=0;i<tot;i++)
	{
		int x=i,cnt=0;
		for(;x;x>>=1)if(x&1)cnt++;//统计1个数
		for(int j=1;j<=n;j++)
			if(i&(1<<(j-1)))
				f[i]=max(f[i],f[i^(1<<(j-1))]*a[cnt][j]);//从没有选第j个任务的状态转移
	}
	printf("%.6lf",f[tot-1]*100);
	return 0;
}