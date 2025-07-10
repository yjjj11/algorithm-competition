#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ull unsigned long long
using PII = pair<int, int>;
using ld = long double;
const int N = 5e5 + 5, M = 998244353;
 
typedef __int128 lll;
istream &operator>>(istream &cin, lll &x) { x=0; static string s; cin>>s; for (char c:s) x=x*10+(c-'0'); return cin; }
ostream &operator<<(ostream &cout, lll x) { static char s[60]; int tp=1; s[0]='0'+(x%10); while (x/=10) s[tp++]='0'+(x%10); while (tp--) cout<<s[tp]; return cout; }
 
// mt19937_64 rng{ chrono::steady_clock::now().time_since_epoch().count() };
 
 
void solve() {
    ll n, k;
    cin >> n >> k;
    ll ans = 1;
    while (n--) {
        ll a;
        cin >> a;
        (ans *= a + k) %= M;
    }
    cout << ans << endl;
}
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int tt = 1;
    // cout << fixed << setprecision(12);
    cin >> tt;
    while (tt--)solve();
}