#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n, k, q, a[N];
vector<int> b[N];
int cnt, root[N], c[N];
struct node {
    int l, r, sum;
} tr[N << 2];

void build(int &now, int l, int r) {
    now = ++cnt;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(tr[now].l, l, mid);
    build(tr[now].r, mid + 1, r);
}

void insert(int pre, int &now, int l, int r, int pos) {
    now = ++cnt;
    tr[now] = tr[pre];
    tr[now].sum++;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (pos <= mid) insert(tr[pre].l, tr[now].l, l, mid, pos);
    else insert(tr[pre].r, tr[now].r, mid + 1, r, pos);
}

int query(int pre, int now, int l, int r, int pos) {
    if (r <= pos) return tr[now].sum - tr[pre].sum;
    if (l > pos) return 0;
    int mid = (l + r) >> 1, ans = 0;
    ans += query(tr[pre].l, tr[now].l, l, mid, pos);
    if (pos > mid) ans += query(tr[pre].r, tr[now].r, mid + 1, r, pos);
    return ans;
}

signed main() {
    scanf("%d%d", &n, &k);
    build(root[0], 0, n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[a[i]].push_back(i);
        if (b[a[i]].size() > k) c[i] = b[a[i]][b[a[i]].size() - k - 1];
        else c[i] = 0;
        insert(root[i - 1], root[i], 0, n, c[i]);
    }
    scanf("%d", &q);
    int lst=0;
    while (q--) {
        int x,y,l, r;
        scanf("%d%d", &x, &y);
        l = (x + lst) % n + 1, r = (y + lst) % n + 1;
        if (l > r) swap(l, r);
        int ans=query(root[l - 1], root[r], 0, n, l - 1);
        cout<<ans<<"\n";
        lst=ans;
    }
}
