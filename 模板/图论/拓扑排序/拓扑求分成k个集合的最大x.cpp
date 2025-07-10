#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,k,a[N],e[N],ne[N],h[N],idx,d[N];
int vis[N],cnt=0,dp[N];
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int check(int x){//无向图与树的做法不同
    cnt=0;
    int dd[N];
    memset(vis,0,sizeof vis);
    memcpy(dd,d,sizeof dd);
    memcpy(dp,a,sizeof dp);
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(d[i]==1)q.push(i);
    }
    while(q.size()){
        int t=q.front();
        q.pop();
        vis[t]=1;
        int sum=dp[t];
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(!vis[j])continue;
            sum+=dp[j];
            
        }
        if(sum>=x){
            cnt++;
            dp[t]=0;
        }
        else dp[t]=sum;
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            dd[j]--;
            if(dd[j]==1)q.push(j);
        }
    }
    return cnt >= k;
}
signed main(){
    cin>>n>>k;
    int sum = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum += a[i];
    }
    memset(h,-1,sizeof h);
    int m;
    cin>>m;
    for(int i=1;i<=m;i++){
        int l,r;
        cin>>l>>r;
        add(l,r),add(r,l);
        d[l]++,d[r]++;
    }
    int l=0, r=sum;
    while(l < r){
        int mid = (l+r+1) / 2;
        if(check(mid)){
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << "\n";
}
