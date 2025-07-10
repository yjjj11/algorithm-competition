#include<bits/stdc++.h>
using namespace std;
const int N=1e4,M=1e6;
int tr[N*50][26],cnt[N*50],ne[N*50],idx;
void insert(string s){
    int p=0;
    for(int i=0;s[i];i++){
        int u=s[i]-'a';
        if(tr[p][u]==0)tr[p][u]=++idx;
        p=tr[p][u];
    }
    cnt[p]++;
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
            if(u==0)tr[t][i]=tr[ne[t]][i];
            else{
                ne[u]=tr[ne[t]][i];
                q.push(u);
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int res=0;
        memset(tr,0,sizeof tr);
        memset(cnt,0,sizeof cnt);
        memset(ne,0,sizeof ne);
        idx=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            insert(s);
        }
        build();
        string s;
        cin>>s;
        for(int i=0,p=0;s[i];i++){
            int u=s[i]-'a';
            p=tr[p][u];
            int kk=p;
            while(kk){
                res+=cnt[kk];
                cnt[kk]=0;
                kk=ne[kk];
            }
        }
        cout<<res<<"\n";
    }
}
