#include<bits/stdc++.h>
using namespace std;
int n,m,s,t,a[20001];
struct each
{
    int x,y,cost;
}b[20001];//���
bool com(each x,each y)
{
    return x.cost<y.cost;
}
int read()//�����Ż�ģ��
{
    char ch=getchar();
    int x=0,f=1;
    while(ch<'0'||ch>'9')
        {
        if(ch=='-')
            f=-1;
        ch=getchar();
        }
    while(ch>='0'&&ch<='9')
        {
        x=x*10+ch-'0';
        ch=getchar();
        }
    return x*f;
}
int find(int x)//���鼯��������
{
    if(a[x]==0)
        return x;
    a[x]=find(a[x]);
    return a[x];
}
int main()
{
    n=read();
    m=read();
    s=read();
    t=read();
    for(int i=1;i<=m;i++)//��������
        {
        b[i].x=read();
        b[i].y=read();
        b[i].cost=read();
        }
    sort(b+1,b+m+1,com);//����
    for(int i=1;i<=m;i++)//��³˹������С����������
        {
        int X=find(b[i].x),Y=find(b[i].y);
        if(X!=Y)
            a[X]=Y;
        if(find(s)==find(t))//�����ֱͨ������˳�
            {
            cout<<b[i].cost<<endl;
            return 0;
            }
        }
    return 0;
}
