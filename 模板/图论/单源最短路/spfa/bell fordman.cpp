#include<bits/stdc++.h>
using namespace std;
struct edges{
    int a,b,c;
}edge[10010];
int n,m,k,dis[505],backup[505];//backup用于保存上一次的状态，防止串联，即保证每次k内循环用的路径变数不会超过当前的i
int bf(){
    for(int i=0;i<k;i++){//类似于bfs的逐层加深
        memcpy(backup,dis,sizeof dis);
        for(int j=0;j<m;j++){//遍历k次每条边
            int a=edge[j].a,b=edge[j].b,c=edge[j].c;
            dis[b]=min(dis[b],backup[a]+c);
        }
    }
    if(dis[n]>=0x3f3f3f3f/2)return 0;//可能存在负权边
    else return dis[n];
}
int main(){
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edge[i]={a,b,c};//保存每条边的信息
    }
    memset(dis,0x3f,sizeof dis);
    dis[1]=0;//从起点一层一层向外推
    int t=bf();
    if(!t)cout<<"impossible";//如果有负权回路，即回路一圈的权和小于0
    else cout<<t;
}
