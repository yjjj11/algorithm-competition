#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 100010, M = 400010, mod = 100003;

int n, m;
int head[N], e[M], ne[M], idx;
int dist[N], cnt[N];  // cnt[i],��1����i�����·��������
int q[N];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = head[a];
    head[a] = idx ++;
}

// ���ܴ��ڳ���Ϊ0�Ļ�
void bfs() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    cnt[1] = 1;

    int hh = 0, tt = 0;
    q[0] = 1; 

    while (hh <= tt) {
        int t = q[hh ++];

        // ��¼һ������㱻����ʱ,��������ǰ��,���Եõ�һ����,���Ǿ����������
        // �涨һ����ֻ�ܱ�һ��ǰ������(����ж�����·һ����ǰ��������,Ҳ��Ϊֻ��һ��)
        for (int i = head[t]; i != -1; i = ne[i]) {
            int j = e[i];  // ö��t�������ٱ�(t���Ը��µ��ĵ�)
            if (dist[j] > dist[t] + 1) {
                dist[j] = dist[t] + 1;  // �����t������j,��tһ���Ѿ������Сֵ
                cnt[j] = cnt[t];  // �������������·���Ļ�, �Ǿ͸�t��ͬһ��·
                q[++ tt] = j;  // ÿ����ֻ���һ�Σ���Ϊ��ʼֵΪ0x3f����ÿ���㶼�ᱻ����һ�Σ���һ����Ӻ󣬺����������dist[t]>=���ڵ�dist[t];
            }else if (dist[j] == dist[t] + 1)  
                cnt[j] = (cnt[j] + cnt[t]) % mod;
        }
    }
}

int main() {
    cin >> n >> m;
    memset(head, -1, sizeof head);

    while (m --){
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }

    bfs();

    for (int i = 1; i <= n; i ++) cout << cnt[i] << endl;

    return 0;
}
