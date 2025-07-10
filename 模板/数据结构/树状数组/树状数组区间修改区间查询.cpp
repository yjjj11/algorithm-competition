#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int tr1[N],tr2[N],a[N],n,m;
void add(int tr[],int x,int d){
    for(int i=x;i<=n;i+=i&-i)tr[i]+=d;
}

int sum(int tr[],int x){
    int res=0;
    for(int i=x;i;i-=i&-i)res+=tr[i];
    return res;
}

int query(int x){
    return sum(tr1,x)*(x+1)-sum(tr2,x);//����a���鵽xΪֹ��ǰ׺��
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        add(tr1,i,a[i]-a[i-1]);//Ҫʵ�������޸ı���ά��һ���������
        add(tr2,i,i*(a[i]-a[i-1]));//Ҫʵ�������ѯһ��Ҫά��һ�������������
    }
    while(m--){
        string op;
        cin>>op;
        if(op=="Q"){
            int l,r;
            cin>>l>>r;
            int res=query(r)-query(l-1);
            cout<<res<<"\n";
        }
        else{
            int l,r,d;
            cin>>l>>r>>d;
            add(tr1,l,d),add(tr1,r+1,-d);
            add(tr2,l,l*d),add(tr2,r+1,(r+1)*(-d));
        }
    }
    
}
