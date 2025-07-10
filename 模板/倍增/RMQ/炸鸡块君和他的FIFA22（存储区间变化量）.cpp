#include<bits/stdc++.h>

using namespace std;
const int N = 2e5+10, M = 21;
int n;
int q;
char s[N];
int st[3][N][M];

void init()
{
    for(int j=0; j<M; ++j)
    {
        for(int i=1; i+(1<<j)-1<=n; ++i)
        {
            if(!j)//根据字符串的内容，我们要对 st 数组进行初始化，根据定义以及题意出发即可
            {
                if(s[i]=='W')//赢 情况
                {
                    st[0][i][j] = st[1][i][j] = st[2][i][j] = 1;
                }
                else if(s[i]=='L')//输 情况 按照题意要根据分数模 3 的结果进行赋值
                {
                    st[0][i][j] = 0;
                    st[1][i][j] = -1;
                    st[2][i][j] = -1;
                }
                else//平局 情况 
                {
                    st[0][i][j] = st[1][i][j] = st[2][i][j] = 0;
                }
            }
            else
            {
                int mid = i+(1<<(j-1));//设置 mid 为区间 [i, j] 的中点，这是倍增算法的套路
                for(int k=0; k<3; ++k)//依据推出来的状态转移方程
                {
                    st[k][i][j] = st[k][i][j-1] + st[((k+st[k][i][j-1])%3+3)%3][mid][j-1];
                }
            }
        }
    }
}

int ask(int l, int r, int start)
{
    int len = r - l + 1;
    //将长度为 len 的区间划分为若干 长度为 2 的若干次幂 的区间
    while(len)
    {
        int k = log(len) / log(2);
        start += st[start%3][l][k];//跳的时候 根据题意一定要根据 模数 来跳
        len -= (1<<k), l += (1<<k);
    }
    return start;
}

int main()
{
    cin>>n>>q;
    cin>>s+1;
    
    init();
    
    while(q--)
    {
        int l, r, start;
        scanf("%d%d%d", &l, &r, &start);
        printf("%d\n", ask(l, r, start));
    }
    
    return 0;
}
