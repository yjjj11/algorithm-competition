#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <time.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxint = -1u>>1;
const int inf = 0x3f3f3f3f;
const int maxn = 3e5 + 10;
int cnt = 1, head[maxn];
int depth[maxn], fa[maxn][20];
int wei[maxn], size[maxn];
int n, a[maxn];
int from, to;

struct EDGE{
    int next, to;
}edge[maxn<<1];

void addedge(int from, int to){
    edge[cnt].to = to;
    edge[cnt].next = head[from];
    head[from] = cnt ++;
}

void dfs(int now = 1, int father = -1, int dep = 1){
    depth[now] = dep;
    for(int i=1;i<=19;i++)
        fa[now][i] = fa[fa[now][i-1]][i-1];
    for(int i=head[now]; ~i; i=edge[i].next){
        int to = edge[i].to;
        if(to == father) continue;
        fa[to][0] = now;
        dfs(to, now, dep + 1);
    }
}

int Lca(int x, int y){
    if(depth[x] < depth[y]) swap(x, y);
    for(int i=19; i>=0; i--){
        if(depth[fa[x][i]] >= depth[y])
            x = fa[x][i];
    }
    if(x == y) return x;
    for(int i=19; i>=0; i--){
        if(fa[x][i] != fa[y][i]){
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

void dfs2(int now = 1, int father = -1){
    size[now] = wei[now];
    for(int i=head[now]; ~i; i=edge[i].next){
        int to = edge[i].to;
        if(to == father) continue;
        dfs2(to, now);
        size[now] += size[to];
    }
}

void print(){
    for(int i=1;i<=n;i++){
        cout<<depth[i]<<' ';
    }
    cout<<endl;
}

int main() {
    memset(head, -1, sizeof(head));
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++){
        cin>>from>>to;
        addedge(from,to);
        addedge(to,from);
    }
    
    dfs();
    
    for(int i=1;i<n;i++){
        wei[a[i]] ++, wei[a[i+1]] ++;
        int lca = Lca(a[i], a[i+1]);
        wei[lca] --;
        wei[fa[lca][0]] --;
    }

    dfs2(); 

    for(int i=2;i<=n;i++){ 
        size[a[i]] --; 
    }

    for(int i=1;i<=n;i++){
        cout<<size[i]<<endl;
    }
    return 0;
}
