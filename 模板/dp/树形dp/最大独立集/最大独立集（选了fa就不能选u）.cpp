#include<bits/stdc++.h>
using namespace std;
int e[10005],ne[10005],h[10005],w[10005],idx,f[6005][2],st[6005];
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void dfs(int u){
    f[u][0]=0;
    f[u][1]=w[u];
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        dfs(j);
        f[u][0]+=max(f[j][0],f[j][1]);
        f[u][1]+=f[j][0];
    }
}
int main(){
    int n;
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        add(b,a);
        st[a]=1;
    }
    int root=1;
    while(root<=n&&st[root])root++;
    dfs(root);
    cout<<max(f[root][0],f[root][1]);
}
