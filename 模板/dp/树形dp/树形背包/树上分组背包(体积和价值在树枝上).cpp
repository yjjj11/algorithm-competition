#include<bits/stdc++.h>
using namespace std;
int f[1005][1005],e[2005],ne[2005],h[1005],idx,w[1005],n,m;
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
void dfs(int u,int fa){
    for(int i=h[u];~i;i=ne[i]){
        int ver=e[i];
        if(ver==fa)continue;
        dfs(ver,u);
        for(int j=m;j>=0;j--){//选子节点时u节点是不用选的，所以和v，w在节点上的类型是不同的
            for(int k=0;k<=j-1;k++){//ver组内选取不同组合，不能等于j，因为边上体积需要留1
                f[u][j]=max(f[u][j],f[u][j-k-1]+f[ver][k]+w[i]);
            }
        }
    }
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
    }
    dfs(1,-1);
    cout<<f[1][m];
}
