#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int N=3e5+10;
int n,tr[N][26],cnt[N],idx,ne[N*26],f[N*26];
vector<int>b;

void insert(string s,int id){
    int p=0;
    for(int i=0;i<s.size();i++){  // 修改：使用 s.size() 而不是 s[i]
        int c=s[i]-'a';
        if(!tr[p][c])tr[p][c]=++idx;
        p=tr[p][c];
    }
    cnt[id]=p;
}

void build(){
    queue<int>q;
    for(int i=0;i<26;i++){
        if(tr[0][i])q.push(tr[0][i]),b.push_back(tr[0][i]);
    }
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int i=0;i<26;i++){
            if(tr[u][i]){
                ne[tr[u][i]]=tr[ne[u]][i];
                q.push(tr[u][i]);
                b.push_back(tr[u][i]);
            }
            else tr[u][i]=tr[ne[u]][i];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    string str[N];
    for(int i=1;i<=n;i++){
        cin>>str[i];
        insert(str[i],i);
    }
    build();
    int p=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){  // 修改：使用 s.size() 而不是 s[i]
        int c=s[i]-'a';
        p=tr[p][c];
        f[p]++;
    }
    for(int i=b.size()-1;i>=0;i--){  // 修改：使用 b.size() 而不是 idx
        f[ne[b[i]]]+=f[b[i]];
    }
    for(int i=1;i<=n;i++){
        cout<<f[cnt[i]]<<"\n";
    }
}
