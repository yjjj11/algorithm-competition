#include <bits/stdc++.h>
using namespace std;
 
#define x first
#define y second
 
const int N = 1e5 + 10;
typedef pair<char, int> PCI;
map<char, int>cnt;
string s;
PCI a[N];
char b[N];
 
void solve()
{
    cin >> s;
    int n = s.size();
    int maxCount = 0;
    for (int i = 0; i < n; i++)
    {
        a[i] = { s[i],i };
        cnt[s[i]]++;
        maxCount = max(maxCount, cnt[s[i]]);
    }
    if (maxCount > n / 2)
    {
        cout << "-1";
        return;
    }
    sort(a, a + n, [](const PCI& p1, const PCI& p2) {
        return p1.x < p2.x;
        });
    for (int i = 0; i < n; i++)
        b[a[i].y] = a[(i + maxCount) % n].x;
    for (int i = 0; i < n; i++)
        cout << b[i];
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}