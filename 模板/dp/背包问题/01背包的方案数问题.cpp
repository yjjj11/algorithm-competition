#include <iostream>

using namespace std;

const int N = 110, M = 10010;

int n, m;
int v[N];
int f[M];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) cin >> v[i];

    f[0] = 1;
    for (int i = 1; i <= n; ++ i)
    {
        for (int j = m; j >= v[i]; -- j)
        {
            f[j] += f[j - v[i]];
        }
    }
    cout << f[m] << endl;
    return 0;
}

