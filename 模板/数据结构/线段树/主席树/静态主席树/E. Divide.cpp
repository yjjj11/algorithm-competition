#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef long long ll;

const int maxn = 2e6;

int tot, n, m;
int sum[(maxn << 5) + 10], rt[maxn + 10], ls[(maxn << 5) + 10], rs[(maxn << 5) + 10];
int a[maxn + 10], ind[maxn + 10], len;

int getid(const int val)
{
    return lower_bound(ind + 1, ind + len + 1, val) - ind;
}

int build(int l, int r)
{
    int root = ++tot;
    if (l == r)
    {
        return root;
    }
    int mid = l + r >> 1;
    ls[root] = build(l, mid);
    rs[root] = build(mid + 1, r);
    return root;
}

int update(int k, int l, int r, int root)
{
    int dir = ++tot;
    ls[dir] = ls[root], rs[dir] = rs[root];
    sum[dir] = sum[root] + 1;
    if (l == r)
    {
        return dir;
    }
    int mid = l + r >> 1;
    if (k <= mid)
    {
        ls[dir] = update(k, l, mid, ls[dir]);
    }
    else
    {
        rs[dir] = update(k, mid + 1, r, rs[dir]);
    }
    return dir;
}

int query(int u, int v, int l, int r, int k)
{
    int mid = l + r >> 1;
    int x = sum[ls[v]] - sum[ls[u]];
    if (l == r)
    {
        return l;
    }
    if (k <= x)
    {
        return query(ls[u], ls[v], l, mid, k);
    }
    else
    {
        return query(rs[u], rs[v], mid + 1, r, k - x);
    }
}

map<int, pair<int, int>> mp; // 构建原来数组中下标到扩充后数组中下标的映射

void init()
{
    cin >> n >> m;
    int idx = 0; // 扩充数组的索引
    int x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        mp[i].first = idx + 1; // 一个原数组中的元素x经扩充后的区间的左端点
        while (x)              // 元素x扩充，扩充到区间[mp[i].first,mp[i].second]里面
        {
            a[++idx] = x;
            x /= 2;
        }
        a[++idx] = 0;       // ai可能等于0，所以要单独将0加入扩充后区间
        mp[i].second = idx; // 一个原数组中的元素x经扩充后的区间的右端点
    }
    // 离散化构建主席树，主席树可用来求出扩充后数组的区间第k小值
    memcpy(ind, a, sizeof(ind));
    sort(ind + 1, ind + idx + 1);
    len = unique(ind + 1, ind + idx + 1) - ind - 1;
    rt[0] = build(1, len);
    for (int i = 1; i <= idx; i++)
    {
        rt[i] = update(getid(a[i]), 1, len, rt[i - 1]);
    }
}

int l, r, k;

void work()
{
    while (m--)
    {
        cin >> l >> r >> k;
        k++; // 当k=i时，求的是第i+1大数，所以k需要++
        // 主席树询问区间：左开右闭
        int left = mp[l].first - 1;
        int right = mp[r].second;
        // 因为左开右闭，所以区间长度即为right-left，而当区间长度小于k+1时，第k+1大值一定为0
        if (right - left < k)
            cout << 0 << '\n';
        else
            cout << ind[query(rt[left], rt[right], 1, len, right - left - k+1)] << '\n'; // right - left + 1 - k的运算是将求第k大值转化为求第right - left + 1 - k小值
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    init();
    work();

    return 0;
}
