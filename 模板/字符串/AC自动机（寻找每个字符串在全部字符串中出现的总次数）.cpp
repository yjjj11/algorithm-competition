#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int tr[N][26],f[N],id[N],ne[N],idx;
vector<int>b;
void insert(string s,int x){
    int p=0;
    for(int i=0;s[i];i++){
        int u=s[i]-'a';
        if(tr[p][u]==0)tr[p][u]=++idx;
        p=tr[p][u];
        f[p]++;
    }
    id[x]=p;
}
void build(){
    queue<int>q;
    for(int i=0;i<26;i++){
        if(tr[0][i])q.push(tr[0][i]);
    }
    
    while(q.size()){
        int t=q.front();
        q.pop();
        for(int i=0;i<26;i++){
            int u=tr[t][i];
            if(!u)tr[t][i]=tr[ne[t]][i];
            else{
                ne[u]=tr[ne[t]][i];
                q.push(u);
                b.push_back(u);
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        insert(s,i);
    }
    build();
    
    for(int i=idx-1;i>=0;i--)f[ne[b[i]]]+=f[b[i]];
    for(int i=1;i<=n;i++)cout<<f[id[i]]<<"\n";
}
