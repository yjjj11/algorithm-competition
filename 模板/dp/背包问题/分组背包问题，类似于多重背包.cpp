#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, f[110] , v[110], w[110];
    cin >> n >> m;
    memset(f,0,sizeof f);
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        for (int j = 0; j < s; j++) {
            cin >> v[j] >> w[j];
        }
        for (int j = m; j >= 0; j--) {
            for (int k = 0; k < s; k++) {
                if (j >= v[k]) {
                    f[j] = max(f[j], f[j - v[k]] + w[k]);
                }
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}
