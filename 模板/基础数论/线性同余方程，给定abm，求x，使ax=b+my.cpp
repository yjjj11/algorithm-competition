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
        int a,b,m,x,aixi��bi(mod mi)
        cin>>a>>b>>m;
        int ans=exgcd(a,m,x,y);
        if(b%ans==0)cout<<x*b/ans%m<<"\n";//aixi��bi(mod mi)��˼����һ��xʹ��a����x����m��������b��Ҳ����ģ��m����b��
        //��(ax)/m��������b
        //���x��m��k(k������С��)����ô��x%m��Ӱ��b�Ĵ�С��������ĿҪ����int��Χ����������x%m����
        else cout<<"impossible\n";
    }
}
