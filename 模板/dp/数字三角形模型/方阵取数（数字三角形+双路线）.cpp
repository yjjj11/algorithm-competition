#include <iostream>

using namespace std;

const int N = 15, M = 2 * N;

int n;
int a, b, c;
int w[N][N];
int f[M][N][N];

int main()
{
    //input
    cin >> n;
    while (cin >> a >> b >> c, a || b || c) w[a][b] += c;
    //dp
    for (int k = 2; k <= 2 * n; ++ k)
    {
        for (int i = 1; i <= n; ++ i)
        {
            for (int j = 1; j <= n; ++ j)
            {
                int &t = f[k][i][j];
                //越界判断
                if (k - i <= 0 || k - i > n || k - j <= 0 || k - j > n) continue;
                //判断是否两条路线走到了相同的格子
                int v = w[i][k - i];
                if (i != j) v += w[j][k - j];//如果两条路线走到一个格子中，则只累加一次物品的价值
                t = max(t, f[k - 1][i - 1][j - 1]);
                t = max(t, f[k - 1][i][j - 1]);
                t = max(t, f[k - 1][i - 1][j]);
                t = max(t, f[k - 1][i][j]);
                t += v;
            }
        }
    }
    //output
    cout << f[2 * n][n][n] << endl;
    return 0;
}
