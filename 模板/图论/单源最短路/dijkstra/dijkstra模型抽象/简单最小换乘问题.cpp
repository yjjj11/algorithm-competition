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
    getline(cin,s);//因为getline回车一次就读一次会造成第一次读入为空
    while (m -- ) {
        string s;
        getline(cin,s);
        stringstream ssin(s);//可以自动分割字符串的字符串流(也是一个容器)，
        int cnt = 0,p;
        while (ssin >> p) stop[cnt ++] = p;//移出字符串流后会自动类型转换
        for (int i = 0;i < cnt - 1;i ++ ) 
            for (int j = i + 1;j < cnt;j ++ ) 
                g[stop[i]][stop[j]] = 1;
    }
    bfs();
    if (d[n] == 1e9) puts("NO");
    else cout << d[n] - 1 << '\n';
    return 0;
}
