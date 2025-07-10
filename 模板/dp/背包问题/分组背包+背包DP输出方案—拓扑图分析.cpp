#include <iostream>
//���  https://www.acwing.com/solution/content/53963/
using namespace std;

const int N = 20;

int n, m;
int w[N][N];
int f[N][N];
int path[N], cnt;

void dfs(int i, int j)
{
    if (!i) return;
    //Ѱ�ҵ�ǰ״̬f[i][j]�Ǵ�������һ��f[i-1][k]״̬ת�ƹ����ģ�
    for (int a = 0; a <= j; ++ a)
    {   //��Ϊ����ĸ��¹����� f(i,j)=max{f(i-1,j-vi)+wi}��wi����w[i][a]������Ҫ�ҵ������·��������ÿ�ζ�����̵�·��һ���ҵ���һ������������a��������return
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
	
    //find path�����dp�����Ĺ�����ʵ����������״̬ת�������ҵ��ӽڵ�00���ڵ�nm�����������
    dfs(n, m);
    for (int i = cnt - 1, id = 1; i >= 0; -- i, ++ id)
        cout << id << " " << path[i] << endl;
    return 0;
}
