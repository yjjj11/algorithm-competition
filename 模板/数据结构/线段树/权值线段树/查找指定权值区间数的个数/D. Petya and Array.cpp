#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,t,a[N],sum[N]={0},b[2*N],tr[8*N],now[N];

void update(int u,int l,int r,int x){
    if(l==r)tr[u]++;
    else{
        int mid=(l+r)>>1;
        if(x<=mid)update(u<<1,l,mid,x);
        else update(u<<1|1,mid+1,r,x);
        tr[u]=tr[u<<1]+tr[u<<1|1];
    }
    return ;
}

int query(int u,int l,int r,int x,int y){
    if(l>=x&&r<=y)return tr[u];
    int mid=(l+r)>>1;
    int res=0;
    if(x<=mid)res+=query(u<<1,l,mid,x,y);
    if(y>mid)res+=query(u<<1|1,mid+1,r,x,y);
    return res;
}

signed main(){
    memset(tr,0,sizeof tr);
    cin>>n>>t;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
        b[i]=sum[i];
        b[i+n]=sum[i]+t;
        now[i]=sum[i]+t;
    }
    b[2*n+1]=0;
    b[2*n+2]=t;
    now[0]=t;
    sort(b+1,b+1+2*n+2);
    int len=unique(b+1,b+1+2*n+2)-b-1;
    for(int i=0;i<=n;i++){
        sum[i]=lower_bound(b+1,b+1+len,sum[i])-b;
    }
    for(int i=0;i<=n;i++){
        now[i]=lower_bound(b+1,b+1+len,now[i])-b;
    }
    update(1,1,len,now[0]);
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=query(1,1,len,sum[i]+1,len);
        update(1,1,len,now[i]);
    }
    cout<<ans<<"\n";
}