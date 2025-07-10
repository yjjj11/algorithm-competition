#include<iostream>
#include<cstring>
#include<map>

using namespace std;

const int N=210;

int res[N][N],g[N][N];
int k,n,m,S,E;
map<int,int> id;

void mul(int c[][N],int a[][N],int b[][N])
{
    static int temp[N][N];
    memset(temp,0x3f,sizeof temp);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                temp[i][j]=min(temp[i][j],a[i][k]+b[k][j]);
    memcpy(c,temp,sizeof temp);
}

void qmi()
{
    memset(res,0x3f,sizeof res);
    for(int i=1;i<=n;i++) res[i][i]=0;//����0����
    while(k)//���µĹ���
    {
        if(k&1) mul(res,res,g);//res=res*g;����k�����Ƿ��õ�ǰg�Ľ��ȥ����res
        mul(g,g,g);//g=g*g;g�ĸ���
        k>>=1;
    }
}

int main()
{
    cin>>k>>m>>S>>E;//��Ȼ�����϶࣬�����ڱ����٣���������ʵ���õ��ĵ���Ҳ���٣�����ʹ��map����ɢ��������
    //����Ψһ�ı��
    memset(g,0x3f,sizeof g);
    //��������������һ��Ϊʲô��ȥ��ʼ��g[i][i]=0�أ�
    //���Ƕ�֪������Floyd�㷨�����ϸ�ı������ƣ����������i->j->i�������ʵ��i->i����������2���ߵ�
    //Ҫ�����ǳ�ʼ��g[i][i]=0,������û���ˣ�Ӱ������Floyd�㷨�ı������ƣ�
    if(!id.count(S)) id[S]=++n;
    if(!id.count(E)) id[E]=++n;
    S=id[S],E=id[E];
    while(m--)
    {
        int a,b,c;
        scanf("%d%d%d",&c,&a,&b);
        if(!id.count(a)) id[a]=++n;
        if(!id.count(b)) id[b]=++n;
        a=id[a],b=id[b];
        g[a][b]=g[b][a]=min(g[a][b],c);
    }
    qmi();
    cout<< res[S][E] <<endl;
    return 0;
}
