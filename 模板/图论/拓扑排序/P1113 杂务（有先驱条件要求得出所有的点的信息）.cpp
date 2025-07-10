#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N = 10005;
queue <int> q;
bool e[N][N];
int ti[N];
int mx[N];
int ru[N];
int n,ans;
void topo()
{
    for(int i=1;i<=n;++i)
        if(ru[i] == 0) 
        {
            q.push(i);
            mx[i] = ti[i];
        }
    while(!q.empty())
    {
        int d = q.front();
        q.pop();
        for(int i=1;i<=n;++i)
        {
            if(e[d][i])
            {
                ru[i]--;
                if(ru[i]==0) q.push(i);
                mx[i] = max(mx[i],mx[d]+ti[i]);
            }
        }
    }
    for(int i=1;i<=n;++i)
        ans = max(ans,mx[i]);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        ti[a] = b;
        while(c!=0)
        {
            ru[a]++;
            e[c][a] = true;
             scanf("%d",&c);
        }
    }
    topo();
    printf("%d",ans);
    return 0;
}
