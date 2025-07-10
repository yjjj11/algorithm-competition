#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100100, M = 400100;

int h[N],e[M],ne[M],idx;
int ans[N*2],cnt;
bool used[M];
int din[N],dout[N];
int n,m,ver;

void add(int a,int b){
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

void dfs(int u){
    for(int &i = h[u]; ~i; ){
        if(used[i]){  //如果这条边用过了
            i = ne[i];   //删除这条边
            continue;
        }

        used[i] = true;  //标记这条边已使用
        if(ver == 1) used[i^1] = true;   //如果是无向图，那么这条边的反向边也要标记使用过了

        int t;
        if(ver == 1){
            t = i/2 + 1;
            if(i&1) t = -t;  //(0,1) (2,3) (4,5) 奇数编号是返回的边

        }else t = i+1;//所有路径都会被输出的

        int j = e[i];
        i = ne[i];
        dfs(j);
        ans[cnt++] = t;
    }
}
int main()
{
    scanf("%d%d%d",&ver,&n,&m);
    memset(h,-1,sizeof h);

    for(int i = 0; i<m; i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
        if(ver == 1) add(b,a);  //无向边
        din[b]++, dout[a]++;   
    }

    if(ver == 1){
        for(int i = 1; i<=n; i++){
            if(din[i]+dout[i] &1){
                //无向图含欧拉回路的充要条件是每个点的度都为偶数
                puts("NO");
                return 0;
            }
        }
    }else{
        for(int i = 1; i<=n; i++){
            if(din[i] != dout[i]){
                //有向图含欧拉回路的充要条件是每个点的入度等于出度
                puts("NO");
                return 0;
            }
        }
    }

    for(int i = 1; i<=n; i++){
        if(~h[i]) {
            dfs(i);
            break;
        }
    }

    if(cnt < m){
        puts("NO");
        return 0;
    }

    puts("YES");
    for(int i = cnt-1; i>=0; --i){
        cout<<ans[i]<<" ";
    }
    return 0;
}
