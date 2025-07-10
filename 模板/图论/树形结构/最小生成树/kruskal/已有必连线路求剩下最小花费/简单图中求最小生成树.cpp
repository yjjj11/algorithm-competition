#include<bits/stdc++.h>
using namespace std;
int p[2100]={};
int find(int x){
    return p[x]==x?x:p[x]=find(p[x]);
}
struct N{
    int a,b,w;
}e[10011];
bool cmp(N a,N b){
    return a.w<b.w;
}
int main(){
    int n,m;
    cin>>n>>m;
    int s=0,x=0;
    for(int i=1;i<=n;i++)p[i]=i;
    for(int i=1;i<=m;i++){
        int ps,u,v,w;
        cin>>ps>>u>>v>>w;
        if(ps==1){
            x+=w;
            p[find(u)]=find(v);
        }
        else {
            e[++s]={u,v,w};
        }
    }
    sort(e+1,e+s+1,cmp);
    for(int i=1;i<=s;i++){
        int a=find(e[i].a),b=find(e[i].b),w=e[i].w;
        if(a!=b){
            p[a]=b;
            x+=w;
        }
    }
    cout<<x;
}
