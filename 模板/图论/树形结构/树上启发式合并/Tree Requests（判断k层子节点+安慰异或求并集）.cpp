# include <iostream>
# include <cstring>
using namespace std;
 
const int N = 500010 , M = 2 * N;
 
int h[N],e[M],ne[M],idx,w[N];
 
int h1[N],e1[N],ne1[N],idx1,w1[N] ;
bool ans[N];
 
int n,m;
 
void add(int a , int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
 
void add1(int a , int b , int c) // 对查询用链进行存储
{
    e1[idx1] = b;
    w1[idx1] = c;
    ne1[idx1] = h1[a];
    h1[a] = idx1++;
}
 
int heavy[N];
int depth[N];
 
int dfs1(int u , int f)
{
    int total = 1;
    int maxvalue = -1;
    heavy[u] = -1;
    for(int i = h[u] ; i != -1 ; i = ne[i])
    {
        int j = e[i];
 
        if(j == f)
        {
            continue;
        }
 
        depth[j] = depth[u] + 1;
 
        int t = dfs1(j,u);
        total += t;
        if(maxvalue < t)
        {
            maxvalue = t;
            heavy[u] = j;
        }
    }
    return total;
}
 
int tag = -1;
int cnt[N]; //cnt[i]: 当前子树下，第i层对应的状态情况。
 
void countnum(int u , int f)
{
    cnt[ depth[u] ] ^= w[u];
 
    for(int i = h[u] ; i != -1 ; i = ne[i])
    {
        int j = e[i];
        if( j == f || j == tag )
        {
            continue;
        }
        countnum(j,u);
    }
}
 
bool check(int u)
{
    int total = 0;
    int temp = u;
 
    while(temp)
    {
        if(temp & 1) // 有1
        {
            total ++;
        }
        temp >>= 1;
    }
 
    if(total <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
 
void dfs2(int u , int f , bool flag)
{
    for(int i = h[u] ; i != -1 ; i = ne[i])
    {
        int j = e[i];
        if(j == f || j == heavy[u])
        {
            continue;
        }
        dfs2(j,u,false);
    }
    if(heavy[u] != -1)
    {
        dfs2(heavy[u],u,true);
        tag = heavy[u];
    }
 
    countnum(u,f); // 算出了u作为子树对应的所有深度的结果
 
    for(int i = h1[u] ; i != -1 ; i = ne1[i])
    {
        int j = e1[i]; // 对应的深度值
        int temp = cnt[j];
 
        if(check(temp))  // 这个值可以
        {
            ans[ w1[i] ] = true;
        }
        else
        {
            ans[ w1[i] ] = false;
        }
    }
 
    tag = -1;
 
    if(!flag)
    {
        countnum(u,f);
 
    }
 
}
 
int main()
{
    memset(h1,-1,sizeof h1);
    memset(h,-1,sizeof h);
 
    scanf("%d %d",&n,&m);
    for(int i = 2 ; i <= n; i++)
    {
        int v;
        scanf("%d",&v);
        add(i,v);
        add(v,i);
    }
    for(int i = 1 ; i <= n ; i++)
    {
        char ch;
        cin >> ch;
        int t = ch - 'a';
        w[i] = 1 << t;
    }
 
    for(int i = 1 ; i <= m ; i++)
    {
        int a , dept;
        scanf("%d %d",&a,&dept);
        add1(a,dept , i);
    }
 
    depth[1] = 1;
 
    dfs1(1,-1);
 
    dfs2(1,-1,0);
 
    for(int i = 1 ; i <= m ; i++)
    {
        if(ans[i])
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
 
    return 0;
}
