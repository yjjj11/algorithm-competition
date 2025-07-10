#include <cstring>
#include <iostream>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 110;

int n, m;
PII match[N][N];
bool g[N][N], st[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
// dfs 
bool find(int x, int y)
{
    for (int i = 0; i < 4; i ++ )//枚举邻点
    {
        int a = x + dx[i], b = y + dy[i];
        if (a && a <= n && b && b <= n && !g[a][b] && !st[a][b])//不是坏点 没遍历过
        {
            // 则男[x,y] 和 女[a,b]能够配对 
            st[a][b] = true;
            PII t = match[a][b];// 
            //1 t.x==-1说明女[a,b]还没和其他人配对 则男[x,y]和女[a,b]可以直接配对
            //2 女[a,b]已经有人配对,但和女[a,b]配对的男t还有其他选项
            //  男t放弃和女[a,b]配对 让女[a,b]给男[x,y]配对(我感动了)
            if (t.x == -1 || find(t.x, t.y))
            {
                match[a][b] = {x, y};
                return true;
            }
        }
    }

    return false;
}

int main()
{
    cin >> n >> m;
    while(m--)
    {
        int x,y;
        cin >> x >> y;
        g[x][y] = true;
    }
    memset(match,-1,sizeof match);
    int res = 0;
    // 枚举所有和为奇数的点
    for(int i=1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            if((i+j)%2 && !g[i][j])
            {
                memset(st,0,sizeof st);//每次都需要清空st数组，因为匹配好的一对可能会有下家
                if(find(i,j))res++;//如果[i,j]能配对
            }
        }
    }
    cout << res << endl;
    return 0;
}
