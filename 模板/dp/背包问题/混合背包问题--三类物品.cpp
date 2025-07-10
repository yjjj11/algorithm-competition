#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N], s[N];
int f[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) cin >> v[i] >> w[i] >> s[i];

    for (int i = 1; i <= n; ++ i)
    {
        //��ȫ����
        if (!s[i])
        {
            for (int j = v[i]; j <= m; ++ j)
            {
                f[j] = max(f[j], f[j - v[i]] + w[i]);
            }
        }
        else
        {
            //�Ѷ��ر����ö������Ż�
            //�����ͱ�������01������
            if (s[i] == -1) s[i] = 1;
            //�������Ż�
            for (int k = 1; k <= s[i]; k *= 2)
            {
                for (int j = m; j >= k * v[i]; -- j)
                {
                    f[j] = max(f[j], f[j - k * v[i]] + k * w[i]);
                }
                s[i] -= k;
            }
            if (s[i])
            {
                for (int j = m; j >= s[i] * v[i]; -- j)
                {
                    f[j] = max(f[j], f[j - s[i] * v[i]] + s[i] * w[i]);
                }
            }
        }
    }

    cout << f[m] << endl;

    return 0;
}

