#include<iostream>
#include<cstring>
#include<algorithm>
#include<deque> //双端队列的头文件，在路径存在的情况下可以移除k条边，使剩余边权最大值最小

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int N = 1002;//定义矩阵边长

bool g[N][N];   //记录位置上是否有障碍物（有：true  无：flase）
bool st[N][N];  //判端是否走过此处（走过：true  无：false）
int dist[N][N];//最短路径距离

int bfs(int sx, int sy){
    
    deque<PII> q;//定义双端队列
    q.push_back({sx, sy});//起点加到双端队列
    memset(dist, 0x3f, sizeof dist);//把距离初始化成正无穷 
    dist[sx][sy] = 0;
    
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};//顺序：上右下左
     
    while(q.size()){//当队列不空
        auto t = q.front();//取出队头元素
        q.pop_front();//删除队头元素、
        
        if(st[t.x][t.y])continue;//判断当前点是否被搜过 
        st[t.x][t.y] = true;//判断当前点是否被搜过 
        
        if(!t.x && !t.y)break;//判断当前点是否被搜过 
        
        for(int i = 0; i < 4; i++){
            int x = t.x + dx[i], y = t.y + dy[i];//求当前方向坐标
            if(x >= 0 && x < N && y >= 0 &&y < N){
                int w = g[x][y]==1 ?1:0;//如果是障碍物，权值置为1 ，否则置为0
                //int w = 0;
                //if (g[x][y]) w = 1;
                if(dist[x][y] > dist[t.x][t.y] + w){//如果距离能被更新且比原有距离更短
                    dist[x][y] = dist[t.x][t.y] + w;//更新权值
                    if(!w) q.push_front({x,y});//加到队头
                    else q.push_back({x, y});//加到队尾
                }
            }
        }
    }
    
    return dist[0][0];
}


int main(){
    int n, sx, sy;//n是障碍物数量，sx，sy是起点
    scanf("%d%d%d", &n, &sx, &sy);
    while(n--){
        int x, y;
        scanf("%d%d", &x, &y);//读入障碍物的坐标
        g[x][y] = true;
    }
    printf("%d\n",bfs(sx,sy));//输出距离原点最短距离 
    
    return 0;
}
