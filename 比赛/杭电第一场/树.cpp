#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=500005;
int h[N],e[2*N],ne[2*N],idx,w[2*N],mod,cnt,ans[N];
vector<int>b,p[N];
void add(int x,int y){
    e[idx]=y,ne[idx]=h[x],h[x]=idx++;
}
void dfs(int u,int fa){
    int len=b.size();
    for(int i=0;i<len;i++){
        ans[b[i]]=(ans[b[i]]+max(w[b[i]],w[u])*abs(w[b[i]]-w[u])*2)%mod;
        p[b[i]].push_back(u);//对路径上的所有父节点注入自己
    }
    len=p[fa].size();//p[fa]中存储当前父节点的所有其他子树的所有元素
    for(int i=0;i<len;i++){
        int t=p[fa][i];//获取其他节点的编号
        ans[fa]=(ans[fa]+max(w[t],w[u])*abs(w[t]-w[u])*2)%mod;//对自己和其它元素进行操作，加到子数组中
    }
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        b.push_back(u);
        dfs(j,u);
        b.pop_back();
        ans[u]=(ans[u]+ans[j])%mod;
    }
}
signed main(){
    int n;
    cin>>n;
    memset(h,-1,sizeof h);
    idx = 0;
    for(int i=1;i<n;i++){ // 输入边
        int u,v;
        cin>>u>>v;
        add(u,v);
    }
    for(int i=1;i<=n;i++) cin>>w[i];
    mod=1,cnt=63;
    while(cnt--) mod*=2;
    memset(ans, 0, sizeof ans); // 初始化 ans 数组
    dfs(1,0);
    int res=0;
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ",res=(res^ans[i])%mod;
    // for(int i=1;i<=n;i++)res=(res^ans[i])%mod;
    cout<<"\n";
    cout<<res;
    return 0;
}