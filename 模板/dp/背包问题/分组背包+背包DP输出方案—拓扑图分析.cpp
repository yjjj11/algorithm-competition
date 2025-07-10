#include <iostream>
//题解  https://www.acwing.com/solution/content/53963/
using namespace std;

const int N = 20;

int n, m;
int w[N][N];
int f[N][N];
int path[N], cnt;

void dfs(int i, int j)
{
    if (!i) return;
    //寻找当前状态f[i][j]是从上述哪一个f[i-1][k]状态转移过来的，
    for (int a = 0; a <= j; ++ a)
    {   //因为本题的更新规则是 f(i,j)=max{f(i-1,j-vi)+wi}，wi就是w[i][a]，我们要找的是最短路径，所以每次都走最短的路，一旦找到第一个满足条件的a就深搜再return
        if (f[i - 1][j - a] + w[i][a] == f[i][j])
        {
            path[cnt ++ ] = a;
            dfs(i - 1, j - a);
            return;
        }
    }
}
int main()
{
    //input
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j)
            cin >> w[i][j];

    //dp
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j)
            for (int k = 0; k <= j; ++ k)
                f[i][j] = max(f[i][j], f[i - 1][j - k] + w[i][k]);
    cout << f[n][m] << endl;
	
    //find path，输出dp方案的过程其实就类似于在状态转移树中找到从节点00到节点nm的最短生成树
    dfs(n, m);
    for (int i = cnt - 1, id = 1; i >= 0; -- i, ++ id)
        cout << id << " " << path[i] << endl;
    return 0;
}
