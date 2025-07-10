#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,a[N],m1=0,m2=0,pos1=0,pos2=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];;
            if(a[i]>m1){
                m1=a[i];
                pos1=i;
            }
        }
        if(n%2==0){
            cout<<m1+n/2<<"\n";
        }
        else{
            if(pos1%2==1){
                cout<<m1+n/2+1<<"\n";
            }
            else{
                int ans=n/2+1;
                for(int i=1;i<=n;i+=2){
                    m2=max(m2,a[i]);
                }
                cout<<max(ans+m2,m1+n/2)<<"\n";
            }
        }
    }
}