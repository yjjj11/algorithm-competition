#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define rep(i ,a ,b) for(int i =a;i<=b;++i)
#define endl '\n'
#define debug(a) cout<<#a<<'='<<a<<endl;
#define inf 0x3f3f3f3f
typedef pair<int,int> pii;
const int N = 1e5+9;
vector<int>g[N];
int  n  ,q;
/*
    1、找出路径上的点
    d[xt] + d[ty] = d[xy]
    2、求出其他点到路径的距离
    做一个01bfs
*/
vector<int> bfs(vector<int>tmp){
    queue<int>q;
    vector<int>dis(n+1 , -1);
    for(auto num : tmp)q.push(num) , dis[num] = 0;
 
    while(!q.empty()){
        auto u =q.front();
        q.pop();
         
        for(auto v :g[u]){
            
            if(dis[v] != -1)continue;//去重
            dis[v] =dis[u] + 1;
            //debug(dis[v]);
            q.push(v);
        }
    }
    return dis;
}
 
void solve(){
    cin>>n>>q;
    rep(i ,1 , n-1){
        int u ,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int x , y;
    cin>>x>>y;
    vector<int> g1 = bfs({x});
    vector<int> g2 = bfs({y});
    vector<int>res;
    int d = g1[y];
    rep(i ,1 , n){
        if(g1[i] + g2[i] ==d )res.push_back(i);//通过在两端的bfs求出路径上的点
    }
    //cout<<324444444444324<<endl;
    vector<int>ans = bfs(res);//多源bfs求出其他点到路径的距离最小值
    int anss = 0;
    for(auto num : ans)anss +=num;
     
    cout<<anss+1;
 
}
  
  
signed main(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int _ = 1;
    //cin>>_; 
    while(_--)solve();
    return 0;
}