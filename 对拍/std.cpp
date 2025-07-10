#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 2e5 + 10;
int spf[MAX];

void sieve() {
    for (int i = 0; i < MAX; i++) spf[i] = i;
    for (int i = 2; i < MAX; i++) {
        if (spf[i] == i) { 
            for (int j = i; j < MAX; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

signed main() {
    sieve();
    int T=1;
//     scanf("%d", &T);
    while (T--) {
        int x, y;
        cin>>x>>y;
        
        if (x == 1 || y == 1) {
            cout<<"-1\n";
            continue;
        }
        
        int g = __gcd(x, y);
        if (g >= 2) {
            cout<<spf[g]<<"\n";
        } else {
            cout<<spf[x] * spf[y]<<"\n";
        }
    }
    return 0;
}
