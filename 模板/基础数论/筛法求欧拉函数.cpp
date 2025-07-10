#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[1000006],p[1000005],vis[1000005],cnt=0,ans=0;
signed main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=2;i<=n;i++){
        if(vis[i]==0)p[++cnt]=i;
        for(int j=i;j<=n;j+=i)vis[j]=1;
    }
    for(int i=1;i<=cnt;i++){
        for(int j=p[i];j<=n;j+=p[i])f[j]=f[j]*(p[i]-1)/p[i];
    }
    for(int i=1;i<=n;i++)ans+=f[i];
    cout<<ans<<"\n";
}
