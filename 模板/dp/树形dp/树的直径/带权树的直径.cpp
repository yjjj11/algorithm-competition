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

int dfs(int u,int father)//father��ʾu�ĸ��ڵ�,��Ϊ��ͼΪ����ͼ,���ҵ��������в��ܻص����ڵ�,����Ҫ������.
{
    int d1=0,d2=0;//��Ϊ��Ŀ��������:ע��:·���п���ֻ����һ����
    //������Ŀ�еĽ��һ����Ϊ����,����·���ɴ˿��Ժ��Ե�
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(j==father) continue;
        int d=dfs(j,u)+w[i];//���·���ĳ���
        //d1,d2����Ըõ�Ϊ������·��
        if(d>=d1) d2=d1,d1=d;//�·���ʹγ�·��
        else if(d>d2) d2=d;
    }

    ans=max(ans,d1+d2);

    return d1;//���ص�ǰ���f[x];
}

int main()
{
    memset(h,-1,sizeof(h));

    int n;
    scanf("%d",&n);

    for(int i=1;i<n;i++)//n-1����
    {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        add(a,b,w),add(b,a,w);
    }

    dfs(1,-1);

    printf("%d",ans);
}
