#include<bits/stdc++.h>
using namespace std;
 
const int N=500010;
 
#define int long long
 
int n,m;
 
int w[N];
 
struct Node{
    int l,r;
    int sum,d;
}tr[N*4];
 
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
 
void pushup(Node& u,Node& l,Node& r){
    u.sum=l.sum+r.sum;
    u.d=gcd(l.d,r.d);
}
 
void pushup(int u){
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}
 
void build(int u,int l,int r){
    if(l==r)tr[u]={l,l,w[l]-w[l-1],w[l]-w[l-1]};
    else {
        tr[u]={l,r};
        int mid=l+r>>1;
        build(u<<1,l,mid);build(u<<1|1,mid+1,r);
        pushup(u);
    }
}
 
Node query(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r)return tr[u];
    else {
        //query每次向下查找的时候mid用当前区间的l，r来更新
        int mid=tr[u].l+tr[u].r>>1;
        if(l>mid)return  query(u<<1|1,l,r);
        else if(r<=mid) return query(u<<1,l,r);
        else {
            Node res;
            auto left=query(u<<1,l,r);
            auto right=query(u<<1|1,l,r);
            pushup(res,left,right);
            return res;
        }
    }
}
 
void modify(int u,int x,int v){
    if(tr[u].l==x&&tr[u].r==x)tr[u]={x,x,tr[u].sum+v,tr[u].sum+v};
    else {
        int mid=tr[u].l+tr[u].r>>1;
        if(x<=mid)modify(u<<1,x,v);
        else modify(u<<1|1,x,v);
        pushup(u);
    }
}
 
 
signed main(){
    scanf("%lld%lld",&n,&m);
    //差分数组无法在一个数组中边输边构造
    for(int i=1;i<=n;i++)scanf("%lld",w+i);
    build(1,1,n);
    while(m--){
        char op[2];
        scanf("%s",op);
        if(op[0]=='Q'){//a,b,c的gcd等于a,b-a,c-b的gcd
            int l,r;
            scanf("%lld%lld",&l,&r);
            auto left=query(1,1,l);
            Node right={0,0,0,0};
            //当操作的是最后一位时右边界不用更新
            if(l+1<=r)right=query(1,l+1,r);
            printf("%lld\n",abs(gcd(left.sum,right.d)));
        }else {
            int l,r,d;
            scanf("%lld%lld%lld",&l,&r,&d);
            modify(1,l,d);
            if(r+1<=n)modify(1,r+1,-d);
        }
    }
    return 0;
}
 
 
 