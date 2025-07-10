#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int fa[N],sz[N],n,a[N];
int find(int x){
    if(fa[x]==x)return x;
    else return fa[x]=find(fa[x]);
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        int ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            fa[i]=i;
            sz[i]=1;
        }
        for(int i=1;i<=n;i++){
            int fx=find(i),fy=find(a[i]);
            if(fx==fy)continue;
            sz[fx]+=sz[fy];
            fa[fy]=fx;
        }
        for(int i=1;i<=n;i++){
            if(fa[i]==i){
                ans+=(sz[i]-1)/2;
            }
        }
        cout<<ans<<"\n";
    }
}