#include<iostream>
#include<cmath>
#define MAXN 1010
#define INF 2000000010
using namespace std;
 
int road[MAXN][MAXN];
int dp[MAXN][MAXN];
 
int main()
{
	int n;
    cin>>n;
	int i,j;
    for(i=1;i<=n;++i)
        for(j=1;j<=i;++j)
            cin>>road[i][j];
     
    dp[n][1]=road[n][1]; //��� 
    for(i=2;i<=n;++i)
		dp[n][i]=INF;
    for(i=2;i<=n;++i) //������ 
		dp[n][i]=min(dp[n][i],dp[n][i-1]+road[n][i]);
	dp[n][n]=min(dp[n][n],dp[n][1]+road[n][n]); //���һ��������ɵ�һ����ֱ�Ӵﵽ�����Σ�
    for(i=n-1;i>=1;--i)//������ 
		dp[n][i]=min(dp[n][i],dp[n][i+1]+road[n][i]);
     
    for(i=n-1;i>=1;--i) //���������� 
    {
        for(j=1;j<=i;++j)//������
            dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+road[i][j];  
        dp[i][i]=min(dp[i][i],dp[i+1][1]+road[i][i]); //�Ҷ� ���� ������һ�����˶������ 
        dp[i][1]=min(dp[i][1],dp[i+1][i+1]+road[i][1]); //��� ���� ����һ����Ҷ˶������ 
         
        dp[i][i]=min(dp[i][i],dp[i][1]+road[i][i]);
        for(j=2;j<=i;++j)//������ 
			dp[i][j]=min(dp[i][j],dp[i][j-1]+road[i][j]);
        
         dp[i][i]=min(dp[i][i],dp[i][1]+road[i][i]);
        for(j=i-1;j>=1;--j)//������ 
			dp[i][j]=min(dp[i][j],dp[i][j+1]+road[i][j]);
        
         dp[i][1]=min(dp[i][1],dp[i][i]+road[i][1]);
        for(j=2;j<=i;++j)//������
			dp[i][j]=min(dp[i][j],dp[i][j-1]+road[i][j]);
        //�������ֻ��ε�dp������Ҫ����������dp��ʵ�����ҷ���ͬ�������ĸ���
         
//         for(j=i-1;j>=1;--j)//������
// 			dp[i][j]=min(dp[i][j],dp[i][j+1]+road[i][j]);
//         dp[i][i]=min(dp[i][i],dp[i][1]+road[i][i]);
    }
     
    cout<<dp[1][1]<<endl;
}
