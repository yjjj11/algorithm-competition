#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
vector<int> p[200005];
int a[200005], dp[200005];

int dfs(int u, int fa) {
    int minn = inf;
    for (auto j : p[u]) {
        if (j == fa) continue;
        int d = dfs(j, u);
        minn = min(minn, d);
    }
    if (minn == inf) {
        dp[u] = a[u];//Ҷ�ӽڵ�
        return dp[u];
    } else {
        if (minn <= a[u]) {
            dp[u] =minn;//����ӽڵ����Сֵ���Լ��ڵ��ֵҩЧ==ҪС����ô��ǰ�ڵ��ֻ��ӵ��minn�ĵ���
            return dp[u];
        } else {//����ӽڵ����Сֵ�ȸ��ڵ��Ҫ��
            dp[u] = a[u] + (minn - a[u]) / 2;//���ڵ��ڱ����ڵ����յ�a[u]������£������Դ��ӽڵ㼳ȡ(minn - a[u]) / 2�ĵ���
            return dp[u];//��Ϊ�ӽڵ�����ڵ�֮�󣬸��ڵ㻹Ҫ�����ڵ㣬�������β����ӽڵ㶼��-1��
            //����Ҫʼ�ձ�֤�ڴ��ݹ������ӽڵ���ڵ��ڸ��ڵ㣬���Ҿ������󸸽ڵ�
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            p[i].clear();
        }
        for (int i = 2; i <= n; i++) {
            int x;
            cin >> x;
            p[x].push_back(i);
        }
        dfs(1, -1);//����ӽڵ��ƽ��ֵ
        int ans = a[1], minn = inf;
        for (auto j : p[1]) {
            minn = min(minn, dp[j]);
        }
        ans += minn;
        cout << ans << "\n";
    }
    return 0;
}
