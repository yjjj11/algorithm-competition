#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,tem;
    ll sum=0;
    cin>>n;
    unordered_map<int,int> mp,mp1;
    for(int i=0;i<n;i++){
        cin>>tem;
        mp[tem]++;
        if(mp[tem]>=2){
            mp1[tem]++;
            sum+=mp1[tem];
        }
        cout<<sum<<" ";
    }
     
}