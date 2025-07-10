#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1e6 + 1;
int n,sz,tot,root[N],ls[N],rs[N],len[N];
char s[N];
inline void read(int&x)
{
    char c = getchar();
    do{
        x = x*10 + c - '0' ;c=getchar();
    }while(c <= '9' && c >= '0');
}
inline void update(int x,int&y,int l,int r,int pos,char c)
{
    y = ++tot;
    ls[y] = ls[x];rs[y]=rs[x];
    if(l == r){ s[y] = c; return ;}//新树的pos叶子节点内存储的就是字母，新字母一定是建在新树的相应节点内的
    int mid = l+r>>1;
    if(pos <= mid) update(ls[x],ls[y],l,mid,pos,c);
    else update(rs[x],rs[y],mid+1,r,pos,c);//对于逐步 插入的序列我么无需在开始建树，字母插入的顺序与其插入的位置相同
}
inline void Q(int x,int l,int r,int pos)//在最新树里查找第pos个字
{
    if(l == r){ printf("%c\n",s[x]);return ;}
    int mid = l+r >> 1;
    if(pos <= mid) Q(ls[x],l,mid,pos);
    else Q(rs[x],mid+1,r,pos);
}
int main()
{
    read(n);
    for(int i = 1;i<=n;i++)
    {
        int x=0;char c;
        for(c = getchar();c != 'Q' && c != 'T' && c!='U' ;c=getchar());
        getchar();
        if(c == 'Q'){ read(x);Q(root[sz],1,n,x); }//sz线段树的第x个字母
        else if(c == 'U') {
            read(x);
            sz++;
            len[sz] = len[sz-x-1];
            root[sz] = root[sz-x-1];
        }
        else if(c == 'T')
        {
            c=getchar();
            sz++;len[sz] = len[sz-1] + 1;
            update(root[sz-1],root[sz],1,n,len[sz],c);
        }
    }
    return 0;
}
