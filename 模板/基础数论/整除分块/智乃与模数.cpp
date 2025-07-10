#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int N, K;
    cin >> N >> K;
    int L = 1, R = N;
    int val = 0, vtot = 0;
    while (L <= R)
    {
        int mid = (L + R) / 2;
        int tot = 0;
        for (int l = 1, r; l <= N; l = r + 1)
        {
            r = N / (N / l);
            int a = N - N / l * l;
            int k = (N / l);
            if (a < mid)continue;
            //cout << "a " << a << " " << mid << endl;
            tot += (a - mid) / k + 1;
        }
        //cout << "aaa " << mid << " " << tot << endl;
        if (tot >= K)
        {
            L = mid + 1;
        } else
        {
            vtot = tot;
            val = mid;
            R = mid - 1;
        }
    }
    //cout << val << " ** " << vtot << endl;
    ll ans = 1LL * (K - vtot) * (val - 1);
    for (int l = 1, r; l <= N; l = r + 1)
    {
        r = N / (N / l);
        int a = N - N / l * l;
        int k = (N / l);
        if (a < val)continue;
        int len = (a - val) / k + 1;
        //cout << "calc " << a << " " << k << " " << len << endl;
        ans += 1LL * (a * 2 - k * (len - 1)) * len / 2;
    }
    printf("%lld\n", ans);
    return 0;
}
