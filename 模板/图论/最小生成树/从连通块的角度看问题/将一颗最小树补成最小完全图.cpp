#include<bits/stdc++.h>
using namespace std;
int t,n,cnt[6005],fa[6005],res=0;
struct node{
    int a,b,c;
    bool operator <(const node &p)const{
        return c<p.c;
    }
}p[6005];
int find(int x){
    if(x==fa[x])return x;
    else return find(fa[x]);
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)fa[i]=i,cnt[i]=1;
        res=0;
        for(int i=1;i<n;i++){
            int a,b,c;
            cin>>a>>b>>c;
            p[i]={a,b,c};
        }
        sort(p+1,p+n);//只有n-1条边
        for(int i=1;i<n;i++){//在合并连通块的过程中累加答案
            int a=find(p[i].a),b=find(p[i].b),c=p[i].c;
            if(a!=b){
                res+=(cnt[a]*cnt[b]-1)*(c+1);
                cnt[a]+=cnt[b],cnt[b]=0;
                fa[b]=a;
            }
            
        }
        cout<<res<<"\n";
    }
}