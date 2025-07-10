#include <cmath>
#include <cstdio>
using namespace std;

const int MAXN = 100005;

int n;
int seq[MAXN], height[MAXN], c[MAXN], prefix[MAXN];

inline int lowbit(int x)
{
    return x & -x;
}

inline int query(int x)
{
    int res = 0;
    while (x) {
        res += c[x];
        x -= lowbit(x);
    }
    return res;
}

inline void modify(int x, int val)
{
    while (x <= n) {
        c[x] += val;
        x += lowbit(x);
    }
}

void init()
{
    scanf("%d", &n);
    for (int i = 2;i <= n;++i) scanf("%d", &seq[i]);
    for (int i = 1;i <= n;++i) c[i] = lowbit(i);
}

void work()
{
    for (int i = n;i >= 1;--i) {
        //query��x����ʾ�����������ʣ�µ����еڼ�С�������Ӻ���ǰ����ÿ��ȥ=ȡʣ�µĵ��е�a[i]+1С�������ɣ�
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (query(mid) < seq[i] + 1) l = mid + 1;
            else r = mid;
        }
        height[i] = l;
        modify(l, -1);//��Ϊ0��������Ѿ���ʹ�ù���
    }
    for (int i = 1;i <= n;++i) {
        printf("%d\n",height[i]);
    }
}

int main()
{
    init();
    work();
    return 0;
}
