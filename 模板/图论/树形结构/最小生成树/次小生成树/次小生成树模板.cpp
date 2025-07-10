// 求最小生成树，统计标记每条边是否是树边；同时把最小生成树建立，权值之和为sum

// 预处理生成树中任意两点间的边权最大值dist1[a][b]和长度次大dist2[a][b] （树中两点路径唯一，dfs）

// 依次枚举所有非MST边t，边t连接a，b,权为w。显然a，b在MST中。
//     尝试用t替换a-b的路径中最大的一条边A。t的权w >= A。（如果w < A,直接换边就能得到更小的生成树，矛盾了）
//     如果w > A,替换后总权值是sum + w - dist1[a][b] 
//     否则 w = A ，不能替换，会得到非严格次小生成树（权值和MST相等）
//     w = A，w > 次大值B 替换后总权值是sum + w - dist2[a][b] 

//  */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 510, M = 10010;
typedef long long LL;

struct Edge{
    int a, b, w;
    bool f = false;
    bool operator < (const Edge & A) const{
        return w < A.w;
    }
}edge[M];

int h[N], e[N * 2], ne[N * 2], w[N * 2], idx; // 无向树 2 * N
int cnt;
int n, m;
int dist1[N][N], dist2[N][N];// 最小和次小
int p[N];
void add(int a,int b,int c){
    e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx ++;
}
int find(int x){
    return x == p[x] ? x : p[x] = find(p[x]);
}

//dfs无向图技巧：记录父节点防止回走
void dfs(int u, int fa, int maxd1, int maxd2, int d1[], int d2[]){
    d1[u] = maxd1, d2[u] = maxd2;
    for (int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if (j != fa){ //不往回搜
            int td1 = maxd1,  td2 = maxd2;
            if (w[i] > td1) td2 = td1, td1 = w[i];
            else if (w[i] < td1 && w[i] > td2) td2 = w[i];
            dfs(j, u, td1, td2, d1, d2);
        }
    }
}


int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    ;
    for(int i = 0; i < m; ++ i){
        int a, b, w;
        cin >> a >> b >> w;
        edge[i] = {a, b, w}; 
    }

    sort(edge, edge + m);
    for(int i = 1; i <= n; ++ i)p[i] = i;
    LL sum = 0;

    for(int i = 0; i < m; ++ i){
        int a = edge[i].a, b = edge[i].b, w = edge[i].w;
        int pa = find(a), pb = find(b); 
        if (pa != pb)
        {
            p[pa] = pb;
            sum += w;
            add(a, b, w), add(b, a, w);//! 合并集合，但加边是节点之间加边
            edge[i].f = true;
        }
    }

    for(int i = 1; i <= n; ++ i)dfs(i, -1, -1e9,-1e9, dist1[i],dist2[i]);// 生成树内搜索最长路

    LL res = 1e18;

    for(int i = 0; i < m; ++ i){ 
        int a = edge[i].a, b = edge[i].b, w = edge[i].w;

        if(!edge[i].f){// 遍历每条外部边尝试替换
            LL t = 1e18;
            if(w > dist1[a][b]){
                t = sum + w - dist1[a][b];
            }else if( w > dist2[a][b]){ // w不是大于就是等于
                t = sum + w - dist2[a][b];
            }
            res = min(res, t);
        }
    }
    cout << res << endl;


    return 0;
}
