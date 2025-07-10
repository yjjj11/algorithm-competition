#include<bits/stdc++.h>
using namespace std;
int u,v,w,n,p,f[105],cnt=1;
struct node{
    int a;
    int b;
    int quan;
};
node e[105],k[105];
bool cmp1(node x,node y){
    return x.quan<y.quan;
}
bool cmp2(node x,node y){
    if(x.a!=y.a)return x.a<y.a;
    else return x.b<y.b;
}
int find(int x){
    if(x==f[x])return x;
    else return f[x]=find(f[x]);
}
void un(int x,int y){
    f[find(y)]=find(x);
}
int main(){
    cin>>n>>p;//p是边的个数
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=p;i++){
        cin>>u>>v>>w;
        if(u>v){
            int temp=u;
            u=v;
            v=temp;           
        }//将两条边中较小的放在前面
        e[i].a=u;
        e[i].b=v;
        e[i].quan=w;
    }
    sort(e+1,e+1+p,cmp1);
    for(int i=1;i<=p;i++){
        if(find(e[i].a)!=find(e[i].b)){
            un(e[i].a,e[i].b);
            k[cnt++]=e[i];//将要当前权值最小并且不会形成环的两个节点连接并保存下来
        }
    }
    sort(k+1,k+cnt,cmp2);
    for(int i=1;i<=cnt-1;i++){
        cout<<k[i].a<<" "<<k[i].b<<"\n";
    }
}
