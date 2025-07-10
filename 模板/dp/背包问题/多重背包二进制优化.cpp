#include<bits/stdc++.h>
using namespace std;
int n,m,f[2010];
struct Good{
    int v,w;
}good[2010];
queue<Good>q;
int main(){
    cin>>n>>m;
    while(n--){
        int v,w,s;
        cin>>v>>w>>s;
        for(int k=1;s>k;k*=2){
            s-=k;
            q.push({k*v,k*w});
        }
        if(s>0)q.push({s*v,s*w});
    }//用二进制优化背包，用几个数来表示s
    while(!q.empty()){
        auto u=q.front();
        q.pop();
        for(int j=m;j>=u.v;j--){
            f[j]=max(f[j],f[j-u.v]+u.w);
        }
    }
    cout<<f[m];
}
