#include<iostream>
#include<cstring>
#include<cstdio>
#define re register
#define maxn 14
#define LL long long
LL dp[maxn][10][10];
LL L,R;
LL ans[10][2];
int a[maxn],num;
inline LL quick(LL a,LL b)
{
	LL s=1;
	while(b)
	{
		if(b&1) s*=a;
		b>>=1;
		a*=a;
	}
	return s;
}
inline void slove(LL x,int pd)
{
    int num=x;
	memset(dp,0,sizeof(dp));
	num=0;
	memset(a,0,sizeof(a));
	while(x)
	{
		a[++num]=x%10;
		x/=10;
	}//�ֽ���λ 
	for(re int i=0;i<=9;i++) dp[1][i][i]=1;//��ʼ��
	for(re int i=2;i<=num;i++)//ö��λ��
		for(re int j=0;j<=9;j++)//��ǰ���λ
		{
			for(re int k=0;k<=9;k++)//�θ�λ
			{
				for(re int p=0;p<=9;p++)
					dp[i][j][p]+=dp[i-1][k][p];
			}
			dp[i][j][j]+=quick(10,i-1);//�˷�ԭ��
		}
	for(re int i=1;i<num;i++)//λ����xС�ģ�һ���ܹ���������
		for(re int j=1;j<=9;j++)//������ǰ����
			for(re int k=0;k<=9;k++)
				ans[k][pd]+=dp[i][j][k];
				
				
	for(re int i=1;i<a[num];i++)//λ����ͬ�������λ��xС
		for(re int k=0;k<=9;k++)
			ans[k][pd]+=dp[num][i][k];
			
	for(re int i=num-1;i>=1;i--)//��ǰ��ͬ����һλ,[i+1,num]��x��ȫ��ͬ 
	{
		for(re int j=0;j<a[i];j++)//��ͬ����һλҲ����ض�Ӧxλ���ϵ���С
		{
			for(re int k=0;k<=9;k++)
				ans[k][pd]+=dp[i][j][k];
		}
		for(re int p=num;p>i;p--)
				ans[a[p]][pd]+=a[i]*quick(10,i-1);
        //�������Ǳ�֤[i+1,num]��ͬ����ô��Щ����ҲӦ�ü���𰸣����ǻ���һ���˷�ԭ��
	}
    //�������dpȫ�̶����ܴ����x�Ƿ���������
    //��Ϊ���Ҳֻ���жϵ�һλ�ϵ����ȸ������ĵ�һλС
    //����slove(x)��ʵ�����[0,x)�������������ĸ���
}
int main()
{
	scanf("%lld%lld",&L,&R);
	slove(R+1,0),slove(L,1);
	for(re int i=0;i<=9;i++)
		printf("%lld ",ans[i][0]-ans[i][1]);
	putchar(10);
	return 0;
}
