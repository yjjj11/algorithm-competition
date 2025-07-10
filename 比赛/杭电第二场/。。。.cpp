#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main{
    int t;
    cin>>t;
    while(t--){
        int n,a[2005];
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+1+n);
        int suma=0,sumb=0,maxn=0,pos=0;
        for(int i=1;i<=n;i+=2){
            sumb+=a[i],suma+=a[i];
            if(a[i+1]-a[i]>maxn){
                maxn=a[i+1]-a[i];
                pos=i;
            }
        }
        suma-=a[pos+1];
        suma+=a[pos];
        sumb-=a[pos];
        sumb+=a[pos+1];
        if(suma>sumb)cout<<"kou\n";
        else if(sumb>suma)cout<<"yukari\n";
        else cout<<"draw\n";
    }
}