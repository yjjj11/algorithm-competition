#include<stdio.h>
#include<queue>
using namespace std;
struct data//��һ���ڽӱ������ͼ
{
    int v;int next;int val;
}edge[1000010];int cnt;
int alist[1000010];
void add(int u,int v,int val)
{
    edge[++cnt].v=v;
    edge[cnt].val=val;
    edge[cnt].next=alist[u];
    alist[u]=cnt;
    return;
}
struct data2//�ڶ����ڽӱ�淴��ͼ���سǵ�·����
{
    int v;int next;int val;
}edge2[1000010];int cnt2;
int alist2[1000010];
void kid(int v,int u,int val)
{
    edge2[++cnt2].v=v;
    edge2[cnt2].val=val;
    edge2[cnt2].next=alist2[u];
    alist2[u]=cnt2;
    return;
}
struct node//һ��ʼ�Բ��뵽����С����������Ҫ���ҡ�����ֱ��int����
{
    int d;int n;
    friend bool operator <(node a,node b)
    {
        return a.d>b.d;
    }
}d[1000010],now;
priority_queue <node> pq;//������int�ͺã���Ҫѧ��
bool book[1000010];
int n;int m;
long long res;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u;int v;int val;
        scanf("%d%d%d",&u,&v,&val);
        add(u,v,val);//����ͼ
        kid(u,v,val);//����ͼ
    }
    for(int i=1;i<=n;i++)//��ʼ��
    {
        d[i].d=0x3f3f3f3f;
        d[i].n=i;
    }
    d[1].d=0;pq.push(d[1]);
    while(!pq.empty())//dijkstraĤ��
    {
        now=pq.top();pq.pop();
        //printf("now %d\n",now.n);
        book[now.n]=true;
        int next=alist[now.n];
        while(next)
        {
            int v=edge[next].v;
            int val=edge[next].val;
            if(book[v]==false)
            {
                if(d[v].d>now.d+val)
                {
                    d[v].d=now.d+val;
                    pq.push(d[v]);
                    //printf("->d[%d]=%d\n",v,d[v].d);
                }
            }
            next=edge[next].next;
        }
    }
    for(int i=1;i<=n;i++)//������ǳ���
    {
        res+=d[i].d;
    }
    for(int i=1;i<=n;i++)//ʡ�������Ǹ�����
    {
        d[i].d=0x3f3f3f3f;
        d[i].n=i;
    }
    d[1].d=0;pq.push(d[1]);
    while(!pq.empty())//����һ��dijkstraĤ��
    {
        now=pq.top();pq.pop();
        //printf("now %d\n",now.n);
        book[now.n]=false;
        int next=alist2[now.n];
        while(next)
        {
            int v=edge2[next].v;
            int val=edge2[next].val;
            if(book[v]==true)//������ʡ��ʡ
            {
                if(d[v].d>now.d+val)
                {
                    d[v].d=now.d+val;
                    pq.push(d[v]);
                    //printf("->d[%d]=%d\n",v,d[v].d);
                }
            }
            next=edge2[next].next;
        }
    }
    for(int i=1;i<=n;i++)//����سǷ���
    {
        res+=d[i].d;
    }
    printf("%lld",res);
    return 0;
}
