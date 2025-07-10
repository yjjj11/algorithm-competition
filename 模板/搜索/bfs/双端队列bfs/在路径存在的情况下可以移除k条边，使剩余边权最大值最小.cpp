#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,inf=1e9;
int n,p,k,e[2*N],ne[2*N],h[N],w[2*N],idx,maxn=0;
int dist[N],st[N];
void add(int x,int y,int z){
	e[idx]=y,w[idx]=z,ne[idx]=h[x],h[x]=idx++;
}
int check(int x){
    deque<int>q;
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);
    dist[1]=0;
    q.push_back(1);
    while(q.size()){
        int t=q.front();
        q.pop_front();
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i],len=w[i];
            int flag=0;
            if(len>x)flag=1;
            if(dist[j]>dist[t]+flag){
                dist[j]=dist[t]+flag;
                if(flag==0)q.push_front(j);//当权值可以归类成两类的时候，就可以通过双端队列来代替优先队列来走dijkstra
                else q.push_back(j);
            }
        }
    }
    
    if(dist[n]==0x3f3f3f3f)return -1;
    else if(dist[n]<=k)return 1;
    else return 0;
}
signed main(){
    cin>>n>>p>>k;
    memset(h,-1,sizeof h);
    for(int i=1;i<=p;i++){
        int a,b,c;
        cin>>a>>b>>c;
        maxn=max(maxn,c);
        add(a,b,c),add(b,a,c);
    }
    
    int l=0,r=maxn;
    while(l<r){
        int mid=(l+r)/2;
        int t=check(mid);
       
        if(t==1)r=mid;
        else if(t==0)l=mid+1;
        else if(t==-1){
            cout<<"-1\n";
            return 0;
        }
    }
    cout<<l;
}
