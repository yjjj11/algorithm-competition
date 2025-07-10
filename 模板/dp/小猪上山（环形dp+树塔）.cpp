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
     
    dp[n][1]=road[n][1]; //起点 
    for(i=2;i<=n;++i)
		dp[n][i]=INF;
    for(i=2;i<=n;++i) //向右走 
		dp[n][i]=min(dp[n][i],dp[n][i-1]+road[n][i]);
	dp[n][n]=min(dp[n][n],dp[n][1]+road[n][n]); //最后一个点可以由第一个点直接达到（环形）
    for(i=n-1;i>=1;--i)//向左走 
		dp[n][i]=min(dp[n][i],dp[n][i+1]+road[n][i]);
     
    for(i=n-1;i>=1;--i) //从下往上走 
    {
        for(j=1;j<=i;++j)//金字塔
            dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+road[i][j];  
        dp[i][i]=min(dp[i][i],dp[i+1][1]+road[i][i]); //右端 顶点 可由下一层的左端顶点过来 
        dp[i][1]=min(dp[i][1],dp[i+1][i+1]+road[i][1]); //左端 顶点 由下一层的右端顶点过来 
         
        dp[i][i]=min(dp[i][i],dp[i][1]+road[i][i]);
        for(j=2;j<=i;++j)//向右走 
			dp[i][j]=min(dp[i][j],dp[i][j-1]+road[i][j]);
        
         dp[i][i]=min(dp[i][i],dp[i][1]+road[i][i]);
        for(j=i-1;j>=1;--j)//向左走 
			dp[i][j]=min(dp[i][j],dp[i][j+1]+road[i][j]);
        
         dp[i][1]=min(dp[i][1],dp[i][i]+road[i][1]);
        for(j=2;j<=i;++j)//向右走
			dp[i][j]=min(dp[i][j],dp[i][j-1]+road[i][j]);
        //对于这种环形的dp我们需要从两个方向dp来实现左右方向不同而带来的覆盖
         
//         for(j=i-1;j>=1;--j)//向左走
// 			dp[i][j]=min(dp[i][j],dp[i][j+1]+road[i][j]);
//         dp[i][i]=min(dp[i][i],dp[i][1]+road[i][i]);
    }
     
    cout<<dp[1][1]<<endl;
}
