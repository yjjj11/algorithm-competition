#include<bits/stdc++.h>
using namespace std;
bool st[200005];
int n,primes[20000],cnt;
void get_primes1(){
    for(int i=2;i<=n;i++){
		if(!st[i])primes[cnt++]=i;
		for(int j=0;primes[j]<=n/i;j++){
			st[primes[j]*i]=true;
			if(i%primes[j]==0)break;
		}
    }
}
int main(){
	cin>>n;
	get_primes1();
}
