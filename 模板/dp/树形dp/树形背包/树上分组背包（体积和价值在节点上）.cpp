#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;

int n, m, root;
int h[N], e[N], ne[N], idx;
int v[N], w[N];
int f[N][N];


void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}
void dfs(int u)
{
    //��ö������״̬���С�ڵ���j-v[u]�������ӽڵ����ܹ���õ�����ֵ
    for (int i = h[u]; ~i; i = ne[i])
    {
        int son = e[i];
        dfs(son); //���������㣬�ȼ����ӽڵ��״̬
        for (int j = m - v[u]; j >= 0; -- j) //ö������Ҫ�����µ�״̬,��u�ڵ�����Ԥ���ռ�
        {
            for (int k = 0; k <= j; ++ k)   //ö�ٸ��ӽڵ������j����ʹ�õ����п��������
            {
                f[u][j] = max(f[u][j], f[u][j - k] + f[son][k]);
            }
        }
    }
    //���ѡ�ϵ�u����Ʒ
    for (int j = m; j >= v[u]; -- j) f[u][j] = f[u][j - v[u]] + w[u];//ѡ������Ʒ�ĸ���
    for (int j = 0; j <  v[u]; ++ j) f[u][j] = 0;   //���ûѡ��u������״̬,��Ϊ���������ڵ���
}
int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i)
    {
        int p;
        cin >> v[i] >> w[i] >> p;
        if (p == -1) root = i;
        else add(p, i);
    }
    dfs(root);
    cout << f[root][m] << endl;
    return 0;
}
