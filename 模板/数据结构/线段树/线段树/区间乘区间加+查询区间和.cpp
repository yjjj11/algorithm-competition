#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int n, p, m;
int w[N];
struct Node{
    int l, r, sum, add, mul; 
} tr[4 * N];

void pushup(int u)
{
    tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % p;
}

void eval(Node &root, int add, int mul)     //�����ڸ�����ӻ��һ���������ݿ��ܻᱬint
{
    root.sum = ((LL)root.sum * mul + (LL)(root.r - root.l + 1) * add) % p;
    root.mul = (LL)root.mul * mul % p;          //�����ƵĹ�ʽ 
    root.add = ((LL)root.add * mul + add) % p;  //�����ƵĹ�ʽ
}

void pushdown(int u)
{
    eval(tr[u << 1], tr[u].add, tr[u].mul);     //�ѵ������������ǿ����ӻ�˲���
    eval(tr[u << 1 | 1], tr[u].add, tr[u].mul); //tr[u].add��Ϊ�����������add��mulͬ��
    tr[u].add = 0;      //ɾȥ�����������
    tr[u].mul = 1;      //ɾȥ�����������
}

void build(int u, int l, int r)
{
    tr[u].r = r, tr[u].l = l;
    if ( l == r ) 
        tr[u].sum = w[l], tr[u].add = 0, tr[u].mul = 1;
    else
    {
        int mid = l + r >> 1;
        tr[u].add = 0, tr[u].mul = 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);      //����ʱͨ����������¸�������Ϣ
    }
}

void modify(int u, int l, int r, int add, int mul)
{
    if ( tr[u].l >= l && tr[u].r <= r ) eval(tr[u], add, mul);  //����ǰ���������ڲ�ѯ������
    else
    {
        pushdown(u);        //�������ʱ���ȴ��������
        int mid = tr[u].r + tr[u].l >> 1;
        if ( mid >= l ) modify(u << 1, l, r, add, mul);         //�ݹ鴦������������
        if ( mid < r ) modify(u << 1 | 1, l, r, add, mul);
        pushup(u);
    }
}

int query(int u, int l, int r)
{
    if ( tr[u].l >= l && tr[u].r <= r ) return tr[u].sum;       //����ǰ���������ڲ�ѯ������
    else
    {
        pushdown(u);        //�������ʱ���ȴ��������                     
        int mid = tr[u].l + tr[u].r >> 1;
        int sum = 0;
        if ( mid >= l ) sum = query(u << 1, l, r) % p;          //�ݹ鴦������������
        if ( mid < r ) sum = (sum + query(u << 1 | 1, l, r)) % p;
        return sum;
    }
}

int main()
{
    scanf("%d%d", &n, &p);
    for ( int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);
    build(1, 1, n);
    scanf("%d", &m);
    while ( m -- )
    {
        int t, l, r, d;
        scanf("%d%d%d", &t, &l, &r);
        if ( t == 1 ) 
        {
            scanf("%d", &d);
            modify(1, l, r, 0, d);
        }
        else if ( t == 2 )
        {
            scanf("%d", &d);
            modify(1, l, r, d, 1);
        }
        else printf("%d\n", query(1, l, r));
    }
    return 0;
}
