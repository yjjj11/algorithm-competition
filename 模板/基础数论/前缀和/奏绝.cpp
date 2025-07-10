#include<bits/stdc++.h>
#define N 200005
using namespace std;
int main() {
    long long a,dp[N]={0},s[2][N]={0},sa[2][N]={0},l,r,ans,n,m,md=998244353;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%1lld",&a);
        sa[0][i]=sa[0][i-1]; s[0][i]=s[0][i-1];
        sa[1][i]=sa[1][i-1]; s[1][i]=s[1][i-1];
        sa[a][i]+=i; s[a][i]++;
        dp[i]=(dp[i-1]+i*s[!a][i]%md-sa[!a][i])%md;
    }  
    while(m--) {
        scanf("%lld%lld",&l,&r);
        ans=dp[r]-dp[l-1]-(sa[0][r]-sa[0][l-1])*s[1][l-1]%md+sa[1][l-1]*(s[0][r]-s[0][l-1])%md-(sa[1][r]-sa[1][l-1])*s[0][l-1]%md+sa[0][l-1]*(s[1][r]-s[1][l-1])%md;
        ans=(ans%md+md)%md;
        printf("%lld\n",ans);
    }
}//前缀和的多次叠加可以大大缩减查询复杂度