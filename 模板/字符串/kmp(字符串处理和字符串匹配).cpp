#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,ne[10000001];
    char p[1000001],s[1000001];
    cin>>n>>p+1>>m>>s+1;
    
    for(int i=2,j=0;i<=n;i++){
        while(j&&p[i]!=p[j+1])j=ne[j];
        if(p[i]==p[j+1])j++;
        ne[i]=j;
    }
    
    for(int i=1,j=0;i<=m;i++){
        while(j&&s[i]!=p[j+1])j=ne[j];
        if(s[i]==p[j+1])j++;
        if(j==n){
            cout<<i-n<<" ";
            j=ne[j];//
        }
    }
}
