#include<bits/stdc++.h>
#define N 310
using namespace std;
struct node{
    int from,to,dis;
}e[N*N];
int n,v,p[N][N];
int fa[N],tot,cnt,ans;
bool rule(const node &x,const node &y)//����Ȩ��С��������
{
    return x.dis<y.dis;
}
int find(int x)//���鼯��������
{
    if(fa[x]==x)
        return x;
    return fa[x]=find(fa[x]);
}
inline void merge(int x,int y)//���鼯��������
{
    fa[find(y)]=find(x);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n+1;i++)//���鼯��ʼ��
        fa[i]=i;
    for(int i=1;i<=n;i++){
        scanf("%d",&v);
        e[++tot].from=n+1;//��"��������վ"��õ���һ��ȨֵΪv�ı�
        e[tot].to=i;
        e[tot].dis=v;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&p[i][j]);
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++){
            e[++tot].from=i;
            e[tot].to=j;
            e[tot].dis=p[i][j];
        }
    sort(e+1,e+1+tot,rule);
    for(int i=1;i<=tot;i++){//��׼��³˹�����㷨
        int u=e[i].from,v=e[i].to;
        if(find(u)!=find(v)){
            merge(u,v);
            ans+=e[i].dis;
        }
    }
    printf("%d\n",ans);
    return 0;
}

