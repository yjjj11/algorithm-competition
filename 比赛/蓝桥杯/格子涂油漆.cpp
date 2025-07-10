#include <bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
long long a[1005],b[1005];

int main()
{
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << 2;
        return 0;
    }
    a[1] = 1,a[2] = 6;
    b[1] = 1,b[2] = 2;
    for(int i = 3;i <= n;i++)
    {
        b[i] = (2 * b[i - 1]) % N;
        a[i] = (2 * a[i - 1] + b[i] + 4 * a[i - 2]) % N;
    }
    long long sum = (4 * a[n]) % N; //必须开long long，否则有可能会溢出
    for(int i = 2;i < n;i++) sum = (sum + 4 * (b[i] * a[n - i] + b[n - i + 1] * a[i - 1])) % N;
    //根据前面算出的a数组和b数组，递推出从中间出发时的方案数量
    //注意i的范围大于1小于n
    cout << sum;
    return 0;
}