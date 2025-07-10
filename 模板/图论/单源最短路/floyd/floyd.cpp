#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
int d[210][210],n,m,k;
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);//有点类似于dp
            }
        }
    }
    
}
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)d[i][j]=0;
            else d[i][j]=inf;
        }
    }
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        d[a][b]=min(d[a][b],c);//由于有重边的存在
    }
    floyd();
    while(k--){
        int x,y;
        cin>>x>>y;
        if(d[x][y]>inf/2)cout<<"impossible\n";
        else cout<<d[x][y]<<"\n";
    }
}
