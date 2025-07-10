#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,a[N],g[N],l[N],tr[N];
int lowerbit(int x){
    return x&-x;
}
void add(int x){
    for(int i=x;i<=n;i+=lowerbit(i))tr[i]++;
}

int sum(int x){
    int res=0;
    for(int i=x;i;i-=lowerbit(i))res+=tr[i];
    return res;
}
signed main(){
    
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    
    for(int i=1;i<=n;i++){
        g[i]=sum(n)-sum(a[i]);
        l[i]=sum(a[i]);
        add(a[i]);
    }
        memset(tr,0,sizeof tr);
        int res1=0,res2=0;
        for(int i=n;i>=1;i--){
            res1+=g[i]*(sum(n)-sum(a[i]));
            res2+=l[i]*(sum(a[i]));
            add(a[i]);
        }
    cout<<res1<<" "<<res2<<"\n";
}
