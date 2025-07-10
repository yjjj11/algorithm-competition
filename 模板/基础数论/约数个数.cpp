#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main()
{
    int T;
    unordered_map<int,int>mp;
    cin >> T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=2;i<=n/i;i++){
          
                while(n%i==0){
                    mp[i]++;
                    n/=i;
                }
            
        }
        if(n>1)mp[n]++;
    }
    long long res=1;
    for(auto it=mp.begin();it!=mp.end();it++){
        res=res*(it->second+1)%mod;
    }
    cout<<res;
}
