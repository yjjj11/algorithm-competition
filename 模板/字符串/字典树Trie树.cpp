#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int son[N][26],cnt[N],idx,n;
char str[N];
void insert(char str[]){
    int p=0;
    for(int i=0;str[i];i++){
        int u=str[i]-'a';
        if(!son[p][u]) son[p][u]=++idx;
        p=son[p][u];
    }
    cnt[p]++;
}
void query(char str[]){
    int p=0;
    for(int i=0;str[i];i++){
        int u=str[i]-'a';
        if(!son[p][u]){
            cout<<0<<"\n";
            return;
        };
        p=son[p][u];//迭代地往下走
    }
    cout<<cnt[p]<<"\n";
}
int main(){
    cin>>n;
    while(n--){
        char op[2];
        scanf("%s%s",op,str);
        if(op[0]=='I')insert(str);
        else query(str);
    }
}
