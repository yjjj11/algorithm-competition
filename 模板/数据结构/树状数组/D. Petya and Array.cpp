#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,a[N]={0},sum[N],tr[4*N],b[2*N],t,len,now[N];
void add(int x){
    for(int i=x;i<=len;i+=i&-i)tr[i]++;
}
int query(int x){
    int res=0;
    for(int i=x;i>=1;i-=i&-i)res+=tr[i];
    return res;
}
signed main(){
    memset(tr,0,sizeof tr);
    cin>>n>>t;
    sum[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
        b[i]=sum[i];
        b[i+n]=sum[i]+t;
        now[i]=sum[i]+t;
    }
    now[0]=t;
    b[2*n+1]=0,b[2*n+2]=t;
    sort(b+1,b+2*n+2+1);
    len=unique(b+1,b+2*n+2+1)-b-1;
    // cout<<len<<"\n";
    // for(int i=1;i<=len;i++)cout<<b[i]<<" ";
    // cout<<"\n";
    for(int i=1;i<=n;i++)sum[i]=lower_bound(b+1,b+len+1,sum[i])-b;
    for(int i=0;i<=n;i++)now[i]=lower_bound(b+1,b+len+1,now[i])-b;
    // for(int i=1;i<=len;i++)cout<<b[i]<<" ";
    // cout<<"\n";
    add(now[0]);
    // cout<<sum[1]<<"\n";
    // cout<<now[0]<<"\n";
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=query(len)-query(sum[i]);//前面比sumr大的(suml+t)有多少个
        // cout<<ans<<" ";
        add(now[i]);
    }
    cout<<ans<<"\n";
}