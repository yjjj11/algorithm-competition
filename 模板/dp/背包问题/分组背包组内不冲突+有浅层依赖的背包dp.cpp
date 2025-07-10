//组内部冲突的分组背包问题
#include<bits/stdc++.h>
using namespace std;
vector<int>p[100];
bool vis[100];
int M,n,m[100],v[100],dp[32005];
void dpp(int i,int j){
    int len=p[i].size();
    for(int a=0;a<1<<len;a++){//用二进制数表示组内组合状态
        int summ=m[i],sumv=v[i];
        for(int lo=0;lo<len;lo++){
            if(a&(1<<lo)){
                summ+=m[p[i][lo]];
                sumv+=v[p[i][lo]];
            }
        }
        if(j>=summ)dp[j]=max(dp[j],dp[j-summ]+sumv);
    }
}
int main(){
    
    cin>>M>>n;
    for(int i=1;i<=n;i++){
        int fa;
        cin>>m[i]>>v[i]>>fa;
        v[i]*=m[i];
        if(fa!=0)p[fa].push_back(i);
        else vis[i]=true;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i])continue;
        for(int j=M;j>=0;j--){
            dpp(i,j);
        }
    }
    cout<<dp[M];
}
