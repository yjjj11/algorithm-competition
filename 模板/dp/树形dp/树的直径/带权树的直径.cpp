#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=10010;

int h[N],w[2*N],ne[2*N],e[2*N],idx;
int ans;

void add(int a,int b,int c)
{
    w[idx]=c,e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int dfs(int u,int father)//father表示u的父节点,因为该图为无向图,并且迭代过程中不能回到父节点,所以要特殊标记.
{
    int d1=0,d2=0;//因为题目描述中有:注意:路径中可以只包含一个点
    //所以题目中的结果一定不为负数,负的路径由此可以忽略掉
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(j==father) continue;
        int d=dfs(j,u)+w[i];//求出路径的长度
        //d1,d2求出以该点为顶点的最长路径
        if(d>=d1) d2=d1,d1=d;//最长路径和次长路径
        else if(d>d2) d2=d;
    }

    ans=max(ans,d1+d2);

    return d1;//返回当前点的f[x];
}

int main()
{
    memset(h,-1,sizeof(h));

    int n;
    scanf("%d",&n);

    for(int i=1;i<n;i++)//n-1条边
    {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        add(a,b,w),add(b,a,w);
    }

    dfs(1,-1);

    printf("%d",ans);
}
