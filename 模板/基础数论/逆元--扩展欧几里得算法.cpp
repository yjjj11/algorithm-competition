#include<bits/stdc++.h>
using namespace std;
#define int long long
int exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1,y=0;
        return 1;
    }
    int ans=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return ans;
}
signed main(){
    int n;
    cin>>n;
    while(n--){
        int a,b,x,y;
        cin>>a>>b;
        int ans=exgcd(a,b,x,y);
        cout<<x<<" "<<y<<"\n";
    }
}
