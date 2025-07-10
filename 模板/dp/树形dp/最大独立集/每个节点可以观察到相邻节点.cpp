#include <iostream>
#include <cstring>
using namespace std;

/*
����ע��Ϊ���ڱʼǣ�ϣ��������������

״̬�� + ����Dp����
״̬��ʾ:
    f(i, 0)����i�Ž�㱻���ĸ���㰲�ŵ�������ס�ķ�����
    f(i, 1)����i�Ž�㱻�����ӽ�㰲�ŵ�������ס�ķ�����
    f(i, 2)����i�Ž���Լ�����������ס�ķ�����
״̬����:(j��i���ӽ��)
    f(i, 0) = sum{min(f(j,1), f(j,2))}
        i�Ǳ�������㿴ס�ģ��������ӽ��Ҫô�Լ����Լ���Ҫô���Լ����ӽ�㿴ס
    f(i, 1) = min{w(k) + f(k, 2) - sum{min(f(j,1), f(j,2))}}
        i����Ǳ��ӽ�㿴ס�ģ���ô��Ҫö�����Ǳ��ĸ��ӽ�㿴ס�����з����������з�������Сֵ
        �����sum������j==k������������Ҫ�ֶ������ȥ
    f(i, 2) = sum{min(f(j,0), f(j,1), f(j,2))} + w(u)
        i�Ǳ��Լ���ס�ģ��������ӽ����Ա�����㿴ס�������Լ����Լ���Ҳ���Ա��Լ����ӽ�㿴ס
*/
const int N = 1510;
int n;
int h[N], w[N], e[N], ne[N], idx;
int f[N][3];
bool st[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u) {
    f[u][0]=0;
    f[u][1]=1e9;
    f[u][2]=w[u];
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        dfs(j);
        f[u][0]+=min(f[j][1],f[j][2]);
        f[u][2]+=min(f[j][0],min(f[j][1],f[j][2]));
    }
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        f[u][1]=min(f[u][1],f[j][2]+f[u][0]-min(f[j][1],f[j][2]));
    }
}
int main() {
    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int id, cnt, cost;
        cin >> id >> cost >> cnt;
        w[id] = cost;
        while (cnt--) {
            int ver;
            cin >> ver;
            add(id, ver);
            st[ver] = true;
        }
    }
    int root = 1;
    while (st[root]) ++root;
    dfs(root);
    printf("%d\n", min(f[root][1], f[root][2]));
    return 0;
}
