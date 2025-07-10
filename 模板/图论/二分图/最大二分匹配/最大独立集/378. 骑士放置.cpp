#include<iostream>
#include<cstring>
#include<algorithm>

#define x first
#define y second

using namespace std;
typedef pair<int,int> PII;
const int N=110;
int n,m,k;
PII match[N][N];
bool g[N][N],st[N][N];

int dirs[8][2] = {{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}};

bool find(int x,int y)
{
    for(int i = 0;i<8;i++)
    {
        int nx = x+dirs[i][0],ny = y+dirs[i][1];
        if(nx<1 || nx>n || ny<1 || ny>m || g[nx][ny] || st[nx][ny]) continue;
        st[nx][ny] = true;//男[x,y] 找到女[nx,ny]
        PII t = match[nx][ny];//t为女[nx,ny]现在匹配的对象
        if(t.x==0||find(t.x,t.y))//如果女[nx,ny]没有匹配对象或者现配t可以去找其他妹子 那就把[nx,ny]给[x,y]
        {
            match[nx][ny] = {x,y};
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> n >> m >> k;
    for(int i = 0;i<k;i++)
    {
        int x,y;
        cin >> x >> y;
        g[x][y] = true;
    }
    int res =0;
    for(int i =1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            if(g[i][j] || (i+j)%2)continue;
            memset(st,0,sizeof st);
            if(find(i,j))res++;
        }
    }
    cout << n*m - k - res << endl;
    return 0;
}
