#include<bits/stdc++.h>
using namespace std;
bool st[200005];
int n,primes[20000],cnt;
void get_primes1(){
    for(int i=2;i<=n;i++){
        if(!st[i]){
            primes[cnt++]=i;
            for(int j=i;j<=n;j+=i) st[j]=true;
        }
    }
}
int main(){
	cin>>n;
	get_primes1();
}
