#include<bits/stdc++.h>
using namespace std;
int dis[150010],cnt[150010],e[150010],h[150010],ne[150010],w[150010],n,m,idx;
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
bool st[150010];
void spfa(){
    memset(dis,0x3f,sizeof dis);
    queue<int>q;
    for(int i=1;i<=n;i++){
        st[i]=true;
        q.push(i);
    }//不确定从那个起点开始可以走到负权边，所以将每个顶点都加进去
    while(q.size()){
        int u=q.front();
        q.pop();
        st[u]=false;
        for(int i=h[u];i!=-1;i=ne[i]){
            int j=e[i];
            if(dis[j]>dis[u]+w[i]){
                dis[j]=dis[u]+w[i];
                cnt[j]=cnt[u]+1;//保留走到该点最小路径的步数；
                if(cnt[j]>=n){//每次循环一圈都会变小，如果更新了n-1次最小值还是没有固定的话说明存在负环
                    cout<<"Yes";
                    return ;
                }//因为不存在负权边的图只需要n-1次就可以更新完
                if(!st[j]){
                    q.push(j);
                    st[j]=true;
                }
            }
        }
    }
    cout<<"No";
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    
    for(int i=0;i<m;i++){
        int a,b,s;
        cin>>a>>b>>s;
        add(a,b,s);
        
    }
    spfa();
}
