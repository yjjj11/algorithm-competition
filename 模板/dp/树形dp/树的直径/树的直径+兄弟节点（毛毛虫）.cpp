#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int e[2*N],ne[2*N],h[N],idx,ans=0;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int dfs(int u,int fa){
    int d1=0,d2=0,cnt=0;;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa)continue;
        cnt++;
        int d=dfs(j,u);
        if(d>=d1)d2=d1,d1=d;
        else if(d>=d2)d2=d;
    }
    d1+=1+max(0,cnt-1);
    if(cnt>=2)ans=max(ans,d1+d2-(fa==-1));//�ڸ��ڵ��ʱ�����У���Ϊd2Ҳ��һ��·��cnt��Ҫ��ȥd2������ӽڵ�
    else ans=max(ans,d1+d2);
    return d1;
}
int main(){
    int n,m;
    cin>>n>>m;
    memset(h,-1,sizeof h);
    while(m--){
        int a,b;
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    dfs(1,-1);
    cout<<ans<<"\n";
}
