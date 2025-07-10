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
        int a=it->first,b=it->second;
        long long t=1;
        while(b--)t=(t*a+1)%mod;
        res=(res*t)%mod;
    }
    cout<<res;
}
// p1---pk为约数c1--ck为各个约数的次数
// 约数之和： (p10+p11+…+p1c1)?…?(pk0+pk1+…+pkck)
