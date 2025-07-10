#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n, m, k;
int match[N];
bool g[N][N], st[N];

bool find(int x)
{
    for(int i=0;i<m;i++)
    {
        if(!st[i] && g[x][i])
        {
            st[i] = true;
            if(match[i]==-1||find(match[i]))
            {
                match[i]=x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    while (cin >> n, n)
    {
        cin >> m >> k;
        memset(g, 0, sizeof g);
        memset(match, -1, sizeof match);

        while (k -- )
        {
            int t, a, b;
            cin >> t >> a >> b;
            if (!a || !b) continue;
            g[a][b] = true;
        }

        int res = 0;
        for (int i = 0; i < n; i ++ )
        {
            memset(st, 0, sizeof st);
            if (find(i)) res ++ ;
        }

        cout << res << endl;
    }

    return 0;
}