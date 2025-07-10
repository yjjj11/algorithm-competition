#include<iostream>
#include<cstdio>
using namespace std;
const int N=3e5+9;
int n,a[N];
int l[N],r[N];
void work()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) l[i]=n+1,r[i]=0;
	for(int i=1;i<=n;i++)
	l[a[i]]=min(l[a[i]],i),r[a[i]]=max(r[a[i]],i);
	for(int i=2;i<=n;i++)
	l[i]=min(l[i],l[i-1]),r[i]=max(r[i],r[i-1]);
	int L=1,R=n;
	for(int i=1;i<=n;i++)
	if(r[i]-l[i]+1>i)
	return puts("0"),void();
	for(int i=1;i<=n;i++)
	if(r[i])
	{
		L=max(L,r[i]-i+1);
		R=min(R,l[i]+i-1);
	}
	printf("%d\n",max(R-L+1,0));
}
signed main()
{
	int T;
	scanf("%d",&T);
	while(T--) work();
}