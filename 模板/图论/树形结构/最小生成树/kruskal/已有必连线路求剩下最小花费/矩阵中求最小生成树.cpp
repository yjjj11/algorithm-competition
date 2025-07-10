#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=2e6+10;
int p[N];
int n,m;//ÁÐ ÐÐ
int find(int x)
{
    if(p[x]!=x)
    p[x]=find(p[x]);
    return p[x];
}
int merge(int a,int b)
{
     int x=find(a);
     int y=find(b);
     if(x!=y)
     {
         p[x]=y;
         return 1;
     }
    return 0;
}
int main()
{    int res=0;
    cin>>m>>n;
    for(int i=1;i<=m*n;i++)
    p[i]=i;
    int x1,y1,x2,y2;
    while(cin>>x1>>y1>>x2>>y2)
    {
        merge((x1-1)*n+y1,(x2-1)*n+y2);
    }
    for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
    {   int a=(i-1)*n+j;
        int b=i*n+j;
        if(a<=m*n&&b<=m*n)
        {
            if(merge(a,b))
            {
                res++;
            }   
        }
    }
     for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
    {   int a=(i-1)*n+j;
        int b=(i-1)*n+j+1;
        if(a<=m*n&&b<=m*n)
        {
            if(merge(a,b))
            {
                res+=2;;
            } 
        }
    }
    cout<<res;
    return 0;
}
