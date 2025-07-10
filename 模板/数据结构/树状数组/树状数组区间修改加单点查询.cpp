#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,a[N],tr[N],m;
int lowerbit(int x){
    return x&-x;
}
void add(int x,int d){
    for(int i=x;i<=n;i+=lowerbit(i))tr[i]+=d;
}

int sum(int x){
    int res=0;
    for(int i=x;i;i-=lowerbit(i))res+=tr[i];
    return res;
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)add(i,a[i]-a[i-1]);
    while(m--){
        string op;
        cin>>op;
        if(op=="Q"){
            int d;
            cin>>d;
            cout<<sum(d)<<"\n";
        }
        else{
            int l,r,d;
            cin>>l>>r>>d;
            add(l,d),add(r+1,-d);
        }
    }
}
