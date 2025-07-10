#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
struct node {
    int l, r;
    int maxn,add,flag;
} tr[N * 4];
int n, k, a[N];

void build(int u, int l, int r) {
    if (l == r) tr[u] = {l, r, a[r], 0, 0};
    else {
        tr[u] = {l, r};
        int mid = (l + r) / 2;
        build(u<<1, l, mid);
        build((u<<1)+1, mid+1, r);
        tr[u].maxn = max(tr[u<<1].maxn, tr[(u<<1)+1].maxn);
    }
}

void pushdown(int u) {
    node &root = tr[u], &l = tr[u<<1], &r = tr[(u<<1)+1];
    if(root.flag==0){
        if (root.add) {
            l.add += root.add,r.add += root.add;
            l.maxn += root.add,r.maxn += root.add;//增加
        }
    }
    else{//修改
        l.add=r.add=root.add;
        l.maxn=r.maxn=root.maxn;
        l.flag=r.flag=root.flag;
    }
    root.add=root.flag=0;//不同操作之后父节点的懒标记信息是要清除的
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].maxn;
    pushdown(u);
    int mid = (tr[u].l + tr[u].r) / 2;
    int res = -1e18;
    if (l <= mid) res = max(res, query(u<<1, l, r));
    if (r > mid) res = max(res, query((u<<1)+1, l, r));
    return res;
}

void modify(int u, int l, int r, int d,int p) {
    if (tr[u].l >= l && tr[u].r <= r) {
        if(p==0){
            tr[u].add += d;
            tr[u].maxn += d;
        }
        else if(p==1){
            tr[u].maxn=d;
            tr[u].add = 0;
            tr[u].flag=1;
        }
        return;
    }
    pushdown(u);
    int mid = (tr[u].l + tr[u].r) / 2;
    if (l <= mid) modify(u<<1, l, r, d,p);
    if (r > mid) modify((u<<1)+1, l, r, d,p);
    tr[u].maxn = max(tr[u<<1].maxn, tr[(u<<1)+1].maxn);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1, 1, n);
    for (int i = 1; i <= k; i++) {
        int op,l,r;
        cin>>op>>l>>r;
        if(op==1){
            int x;
            cin>>x;
            modify(1,l,r,x,1);
        }
        else if(op==2){
            int x;
            cin>>x;
            modify(1,l,r,x,0);
        }
        else{
            cout<<query(1,l,r)<<"\n";
        }
    }
}
