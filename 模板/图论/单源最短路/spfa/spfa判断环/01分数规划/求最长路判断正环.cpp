#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010, M = 5010;
const double eps = 1e-4;

int n, m;
int w_ver[N];
int h[N], e[M], w_edg[M], ne[M], idx;
double dist[N];
int cnt[N], q[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w_edg[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
//spfa�㷨�������һ�����ʣ�������������·��ʱ���ǿ��԰ѵ�Ȩ�ͱ�Ȩ����һ�������Ȩһ����µģ�������ǳ�����һЩspfa��ͼ�������У��ѵ�Ȩ�����Ȩ�н��м��㡣
//��ͼ���Ƿ�������������󸺻���һ���Գ����⣬ֱ�Ӹ���spfa�㷨�еĲ��Ⱥŷ���ת��������·�㷨���Ƿ�������������ɰ쵽��������������������
bool check(double limit) {
    memset(dist, 0, sizeof dist);
    memset(cnt, 0, sizeof cnt);
    memset(st, 0, sizeof st);

    int hh = 0, tt = 0;
    for (int i = 1; i <= n; ++i) {
        q[tt++] = i;
        st[i] = true;
    }

    while (tt != hh) {
        int t = q[hh++];
        if (hh == N) hh = 0;
        st[t] = false;

        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            //�������Ƿ�������������spfa��Ѱ�ҡ����·����ΪѰ�ҡ��·��
            if (dist[j] < dist[t] + w_ver[t] - limit * w_edg[i]) {
                dist[j] = dist[t] + w_ver[t] - limit * w_edg[i];
                cnt[j] = cnt[t] + 1;

                if (cnt[j] >= n) return true;

                if (!st[j]) {
                    st[j] = true;
                    q[tt++] = j;
                    if (tt == N) tt = 0;
                }
            }
        }
    }
    return false;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &w_ver[i]);

    memset(h, -1, sizeof h);
    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    double l = 1, r = 1000;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    printf("%.2lf\n", l);
    return 0;
}

