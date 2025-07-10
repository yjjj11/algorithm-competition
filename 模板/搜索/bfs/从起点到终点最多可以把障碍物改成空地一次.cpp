#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define ll long long
#define endl "\n"
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
struct node{
    int x,y,k,ban,dis;
};
char arr[1005][1005];
int vis[1005][1005][2][5];
queue<node> q;
void solve(){
    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin >> arr[i][j];
        }
    }
    q.push({1,1,0,0,0});
    q.push({1,1,0,1,0});
    q.push({1,1,0,2,0});
    q.push({1,1,0,3,0});//类似于状态机，要存储到当前位置前面是否已经搬过了
    q.push({1,1,1,4,0});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        int x = p.x,y = p.y,k = p.k,ban = p.ban,dis = p.dis;
        if(vis[x][y][k][ban]) continue;
        vis[x][y][k][ban] = 1;
        if(x == n&&y == m){
            cout << dis << endl;
            return;
        }
        for(int i = 0;i<4;i++){
            if(i == ban) continue;
            int xx = x+dx[i],yy = y+dy[i];
            if(xx>0&&yy>0&&xx<=n&&yy<=m){
                if(arr[x][y] == 'X'){
                    if(k == 0) q.push({xx,yy,1,ban,dis+1});
                }
                else
                    q.push({xx,yy,k,ban,dis+1});
            }
        }
    }
    cout << -1 << endl;
}
 
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
