#include <bits/stdc++.h>
using namespace std;
int n,m,k,s,t,f[111111][21];
struct edge
{
	int next,to,vl;
}p[1111111];
int head[1111111],num;
void ad(int x,int y,int z)
{
	p[++num].next=head[x];
	p[num].to=y;
	p[num].vl=z;
	head[x]=num;
}
struct vs
{
	int x,vl;
	vs(int a,int b)
	{
		x=a;
		vl=b;
	}
	bool operator <(const vs b) const
    {
        return vl>b.vl;
    }
};
priority_queue<vs> q;
void djstl()
{
	for(int i=0;i<=k;i++) f[s][i]=0;
	for(int i=0;i<=k;i++)//for·ÅÍâÃæ
	{
		q.push(vs(s,0));
		while(!q.empty())
		{
			vs u=q.top();
			q.pop();
			if(u.vl>f[u.x][i]) continue;
			for(int j=head[u.x];j;j=p[j].next)
			{
				int v=p[j].to;
				bool bl=0;
				if(i)
				if(f[v][i]>f[u.x][i-1])
				{
					f[v][i]=f[u.x][i-1];
		//			printf("!%d %d %d %d %d\n",u.x,v,i,j,f[v][i]);	
					bl=1;
				}
				if(f[v][i]>f[u.x][i]+p[j].vl)
				{
					f[v][i]=f[u.x][i]+p[j].vl;
		//			printf("@%d %d %d %d %d\n",u.x,v,i,j,f[v][i]);	
					bl=1;
				}
				if(bl)
				{
					q.push(vs(v,f[v][i]));
				}
			}
		}
	}
}
int main()
{
	cin>>n>>m>>k>>s>>t;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		ad(x,y,z);
		ad(y,x,z);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=k;j++) f[i][j]=1e9;
	}
	djstl();
//	printf("%d %d\n",f[0][0],f[2][1]);
	printf("%d",f[t][k]);
	return 0;
}
