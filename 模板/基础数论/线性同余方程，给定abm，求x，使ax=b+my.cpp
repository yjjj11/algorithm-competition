#include<bits/stdc++.h>
using namespace std;
#define int long long
int exgcd(int a,int b,int &x,int &y){
    if(!b){
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
signed main(){
    int n;
    cin>>n;
    while(n--){
        int a,b,m,x,aixi≡bi(mod mi)
        cin>>a>>b>>m;
        int ans=exgcd(a,m,x,y);
        if(b%ans==0)cout<<x*b/ans%m<<"\n";//aixi≡bi(mod mi)意思是求一个x使得a乘以x除以m的余数是b（也就是模上m等于b）
        //即(ax)/m的余数是b
        //如果x是m的k(k可以是小数)倍那么把x%m不影响b的大小，所以题目要求在int范围，所以最后把x%m即可
        else cout<<"impossible\n";
    }
}
