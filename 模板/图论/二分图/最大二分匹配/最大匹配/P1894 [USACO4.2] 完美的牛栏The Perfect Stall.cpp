#include<bits/stdc++.h>
using namespace std;
const int N=2e6,M=1e9+7;
int n,m,ans=0;
int e[N],ne[N],h[N],idx;
int match[N],st[N];
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
bool find(int x){
    for(int i=h[x];~i;i=ne[i]){
        int j=e[i];
        if(st[j])continue;
        st[j]=1;
        if(match[j]==0||find(match[j])){
            match[j]=x;
            return true;
        }
    }
    return false;
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        int num,p;
        cin>>num;
        while(num--){
            cin>>p;
            add(i,p);
        }
    }
    for(int i=1;i<=n;i++){
        memset(st,0,sizeof st);
        if(find(i))ans++;
    }
    cout<<ans<<"\n";

}
