#include<bits/stdc++.h>
using namespace std;
const int N=4e6+10,mod=100003;
int n,m;
int h[N],e[N],ne[N],idx,dis[N],f[N];
vector<int>b;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void spfa(){
    for(int i=1;i<=n;i++)dis[i]=1e9;
    queue<int>q;
    int st[N];
    memset(st,0,sizeof st);
    q.push(1),f[1]=1,dis[1]=0,st[1]=1;
    while(q.size()){
        int t=q.front();
        q.pop();
        st[t]=0;
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            if(dis[j]>dis[t]+1){
                dis[j]=dis[t]+1,f[j]=f[t];
                if(!st[j])st[j]=1,q.push(j);
            }
            else if(dis[j]==dis[t]+1)f[j]=(f[j]+f[t])%mod;
        }
    }
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    spfa();
    for(int i=1;i<=n;i++)cout<<f[i]<<"\n";
}