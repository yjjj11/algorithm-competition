#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 105,M = 12;
typedef pair<int,int> PII;
int g[N][N],key[N],d[N][1<<M];
//地图g[x][y]=z。z>=1,xy两点间有第z类门，z=0,两点间有墙。g初始化为-1
//key[i]编号为i的格子的钥匙,钥匙编号从1开始
//d最短路
bool st[N][1<<M];//遍历过
int n,m,p,k,s;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
queue<PII> q;
int get(int x,int y){//把坐标转化为格子的编号，从1开始,题目的地图从（1，1）开始
    return (x - 1) * m + y;
}
//队列非空时不断出队，取队头元素，尝试向四个方向转移
int bfs(){
    int t = get(1,1);
    q.push({t,key[t]});//初始状态是{1,key[1]}，格子编号，该格子的钥匙状态
    st[t][key[t]] = true;
    memset(d,0x3f,sizeof d);
    d[t][key[t]] = 0;
    while(q.size()){
        PII u = q.front();
        q.pop();
        int z = u.first,v = u.second;
        for(int i = 0;i < 4;i++){
            int x = (z - 1) / m + dx[i] + 1,y = (z - 1) % m + dy[i] + 1;
            int v1 = v,z1 = get(x,y);//z旧点的编号，z1新点的编号
            if(!x || !y || x > n || y > m || !g[z][z1]) continue;//出界，墙
            if(g[z][z1] != -1){
                if(!(v >> g[z][z1] & 1))    continue;
                //有门但是无钥匙。v的二进制数的第g[z][z1]位是否为1
               //v旧格子的钥匙状态，v1新格子的钥匙状态。
            }

            //排除上面不能通行的点，剩可以直接过和有门有钥匙的点
            v1 |= key[z1];//新点z1的钥匙状态，无论有无都直接继承
            if(!st[z1][v1]){
                q.push({z1,v1});
                st[z1][v1] = true;
                d[z1][v1] = d[z][v] + 1;
            } 
            if(z1 == n * m) return d[z1][v1];//终点z1
        }
    }
    return -1;
}
int main(){
    cin>>n>>m>>p;// P 类门
    cin>>k;//门和墙的总数。
    int x1,y1,x2,y2,z,z1,z2;
    memset(g,-1,sizeof g);
    //z>=1,两点间有第z类门，z=0,两点间有墙
    while(k--){
        cin>>x1>>y1>>x2>>y2>>z;
        z1 = get(x1,y1),z2 = get(x2,y2);
        g[z1][z2] = g[z2][z1] = z;//双向边
    }
    cin>>s;//钥匙的总数
    while(s--){
        cin>>x1>>y1>>z;//(Xi1,Yi1)存放第 Qi 类门的钥匙
        key[get(x1,y1)] |= 1 << z;
        //key[i]第i个格子的第z位有钥匙。
        //z=0110时，表示持有第1,2类钥匙
        //或运算：只要有一个为1，其值为1。
    }
    cout<<bfs()<<endl;
    return 0;
}