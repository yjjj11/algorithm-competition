#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int h[N],e[N],ne[N],idx,d[N],f[N],ans;
vector<int>b;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void topsort(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!d[i]) q.push(i),b.push_back(i);
    }
    while(q.size()){
        int t=q.front();
        q.pop();
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            f[j]=max(f[j],f[t]+1);
            if(--d[j]==0) q.push(j),b.push_back(j);
        }
    }
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        add(a,b),d[b]++;
    }
    topsort();
    for(int i=1;i<=n;i++)cout<<f[i]+1<<"\n";
}