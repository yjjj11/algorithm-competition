#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+6;
int n,k,a[N],maxn=0,sum=0;
int check1(int l,int r,int x){
    while(l<r){
        int mid=(l+r)/2;
        if(a[mid]<=x)l=x;
        else r=mid-1;
    }
    return l;
}
int check(int x){
    int be=1,p=k,tot=0,now=0;
    while(p--){
        now=check1(be,n,x+tot);
        if(now==n)return 1;
        be=now;
        tot=a[now];
    }
    if(now<n)return 0;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            maxn=max(maxn,a[i]);
            sum+=a[i];
            a[i]+=a[i-1];
        }
        int av=(sum+k-1)/k;
        if(av<=maxn)cout<<maxn<<"\n";
        int l=0,r=1e18;
        while(l<r){
            int mid=(l+r)/2;
            if(check(mid))r=mid;
            else l=mid+1;
        }
        cout<<l<<"\n";
    }
}