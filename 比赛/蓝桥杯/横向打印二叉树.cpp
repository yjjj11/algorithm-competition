#include <bits/stdc++.h>
using namespace std;
const int N=110;
struct Node
{
	int val/*数值*/, h, z, l/*左儿子*/, r/*右儿子*/;//h，z表示该数的第一个字符在第h行第z列输出 
}tr[N];//结构体存树 
int idx/*编号*/, root/*根*/, h/*行数*/;
char c[110][10010];//字符数组 

void insert(int &u, int x)//插入函数 
{
	if (!u)//访问到空节点，就在这里插入 
	{
		u=++idx;//赋一个新的编号给u 
		tr[u].val=x;//新节点的数值为x 
		return;
	}
	else if (x<tr[u].val) insert(tr[u].l,x);//在左边插入 
	else if (x>tr[u].val) insert(tr[u].r,x);//在右边插入 
}

void print(int u, int sum)//sum表示该节点前的字符数 
{
	if (!u) return;//边界
	int t=tr[u].val, cnt=0;//拆数，cnt为位数
	char num[10];
	while (t) num[++cnt]=t%10+'0', t/=10;
	reverse(num+1,num+cnt+1);
	print(tr[u].r,sum+3+cnt);//递归打印右边
	h++;//h为行数
	tr[u].h=h;
	if (sum)//该节点前有字符 
	{
		for (int i = 1; i <= sum-2; i++) c[h][i]='.';//把第h行（即当前行）1~sum-2位设置成'.'
		c[h][sum-1]='|', c[h][sum]='-';
	}
	tr[u].z=sum+1;//该值的第一个字符的列数为sum+1 
	for (int i = 1; i <= cnt; i++) c[h][sum+i]=num[i];//把sum后的cnt位设置成数
	if (tr[u].l||tr[u].r) c[h][sum+cnt+1]='-', c[h][sum+cnt+2]='|';//如果不是叶子，把后两位设置成"-|" 
	print(tr[u].l,sum+3+cnt);//递归打印左边
}

void work(int u)
{
	if (!u) return;//边界 
	int uh=tr[u].h;
	if (tr[u].r)//连接右儿子 
	{
		int rh=tr[tr[u].r].h, rz=tr[tr[u].r].z;
		for (int i = rh; i <= uh; i++) c[i][rz-2]='|';//循环修改
	}
	if (tr[u].l)//连接左儿子 
	{
		int lh=tr[tr[u].l].h, lz=tr[tr[u].l].z;
		for (int i = uh; i <= lh; i++) c[i][lz-2]='|';//循环修改
	}
	work(tr[u].l), work(tr[u].r);//递归 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x;
	while (cin >> x) insert(root,x);//插入x 
	print(root,0);//从根开始打印，根前有0个字符 
	work(root);//从根开始连接 
	for (int i = 1; i <= h; i++)//输出 
	{
		for (int j = 1; c[i][j]; j++) cout << c[i][j];
		cout << "\n";
	}
	return 0;
}