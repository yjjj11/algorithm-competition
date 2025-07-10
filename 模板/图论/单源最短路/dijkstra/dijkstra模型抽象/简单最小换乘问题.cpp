#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <sstream>
using namespace std;
const int N = 1010;
int g[N][N],d[N],stop[N];
int m,n,idx;

void bfs()
{
    for (int i = 1;i <= n;i ++ ) d[i] = 1e9;
    d[1] = 0;
    queue<int> q;
    q.push(1);

    while (q.size()) {
        int t = q.front();
        q.pop();
        for (int i = 1; i <= n; i ++ ) {
            if (g[t][i] && d[i] == 1e9) {
                d[i] = d[t] + 1;
                q.push(i);
            }
        }
    }
}
int main()
{   
    cin >> m >> n;
    string s;
    getline(cin,s);//��Ϊgetline�س�һ�ξͶ�һ�λ���ɵ�һ�ζ���Ϊ��
    while (m -- ) {
        string s;
        getline(cin,s);
        stringstream ssin(s);//�����Զ��ָ��ַ������ַ�����(Ҳ��һ������)��
        int cnt = 0,p;
        while (ssin >> p) stop[cnt ++] = p;//�Ƴ��ַ���������Զ�����ת��
        for (int i = 0;i < cnt - 1;i ++ ) 
            for (int j = i + 1;j < cnt;j ++ ) 
                g[stop[i]][stop[j]] = 1;
    }
    bfs();
    if (d[n] == 1e9) puts("NO");
    else cout << d[n] - 1 << '\n';
    return 0;
}
