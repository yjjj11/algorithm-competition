#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int N=1.5e5+10;
int n,tr[N][26],cnt[N*26],idx,ne[N*26],num[200];
void insert(string s,int id){
    int p=0;
    for(int i=0;i<s.size();i++){
        int c=s[i]-'a';
        if(!tr[p][c])tr[p][c]=++idx;
        p=tr[p][c];
    }
    cnt[p]=id;
}
void build(){
    queue<int>q;
    for(int i=0;i<26;i++){
        if(tr[0][i])q.push(tr[0][i]);
    }
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int i=0;i<26;i++){
            if(tr[u][i]){
                ne[tr[u][i]]=tr[ne[u]][i];
                q.push(tr[u][i]);
            }
            else tr[u][i]=tr[ne[u]][i];
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    while(n!=0){
        memset(tr,0,sizeof tr);
        memset(cnt,0,sizeof cnt);
        memset(ne,0,sizeof ne);
        memset(num,0,sizeof num);
        idx=0;
        string str[200];
        for(int i=1;i<=n;i++){
            cin>>str[i];
            insert(str[i],i);
        }
        build();
        string s;
        cin>>s;
        int res=0,p=0;

        for(int i=0;s[i];i++){
            int p=tr[p][s[i]-'a'];
            int kk=p;
            while(kk){
                if(cnt[kk]){
                    num[cnt[kk]]++;
                    res=max(res,num[cnt[kk]]);
                }
                kk=ne[kk];
                
            }
        }
        cout<<res<<"\n";
        for(int i=1;i<=n;i++){
            if(num[i]==res)cout<<str[i]<<"\n";
        }
        
        cin>>n;
    }
}