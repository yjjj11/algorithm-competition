#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
inline int read(){
	int x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*y;
}
int T,n,m,q,cnt,a[N],b[N],p[N];
set<int>S[N];
inline void SOLVE()
{
	n=read(),m=read(),q=read(),cnt=0;
	for(int i=1;i<=n+1;i++)S[i].clear(),S[i].insert(m+1);
	for(int i=1;i<=n;i++)a[i]=read(),p[a[i]]=i;//每个数字在a序列中的位置
	for(int i=1;i<=m;i++)b[i]=p[read()],S[b[i]].insert(i);//保存a中每个位置上的数分别在b的那些位置取到;
    //若a中第i个数字在b中<i的位置中取到，则是违法的
	for(int i=2;i<=n;i++)if(*S[i-1].begin()>*S[i].begin())cnt++;//如果钱一个位置的数最早出现的位置在当前数字最早出现位置之后，则根本轮不到当前数字
	puts(cnt?"TIDAK":"YA");
	while(q--)
	{
		int x=read(),y=p[read()],v=b[x];
		bool L=*S[v].begin()<*S[v-1].begin(),
			 R=*S[v].begin()>*S[v+1].begin();
		S[v].erase(x), // 比较删除前和删除后的，所以先记录下删除前的大小关系
		cnt+=((*S[v].begin()>*S[v+1].begin())-R),
		cnt+=((*S[v].begin()<*S[v-1].begin())-L),
		L=*S[y].begin()<*S[y-1].begin(),
		R=*S[y].begin()>*S[y+1].begin(),
		b[x]=y,S[y].insert(x),
		cnt+=((*S[y].begin()>*S[y+1].begin())-R),
		cnt+=((*S[y].begin()<*S[y-1].begin())-L),
		puts(cnt?"TIDAK":"YA");
	}
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read();S[0].insert(0);while(T--) SOLVE();system("pause");return 0;
}