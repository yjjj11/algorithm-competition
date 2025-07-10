#include<bits/stdc++.h>

using namespace std;

const int N = 2e5+10, M = 18;
int n, q;
int a[N];

int st[N][M];

void init()
{
        for(int j=0; j<M; ++j)
        {
                for(int i=1; i+(1<<j)-1<=n; ++i)
                {
                        if(!j) st[i][j] = a[i];//当区间长度为 1 的时候直接赋值
                        else st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
                }
        }
}


int ask(int l, int r)
{
    int len = r - l + 1;
    int k = log(len) / log(2);

    return max(st[l][k], st[r - (1 << k) + 1][k]);
}


int main()
{
        cin>>n;
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);

        init();
        cin>>q;

        while(q--)
        {
                int l, r;
                scanf("%d%d", &l, &r);
                printf("%d\n", ask(l, r));
        }

        return 0;
}
