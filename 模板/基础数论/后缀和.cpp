#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,s[2200005],q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i];
	int a[200005][500],b[200005][500];
	for(int i=n;i;i--){
		for(int j=1;j<500;j++)a[i][j]=b[i][j]=0;
	}
	int up=sqrt(n)+1;
	for(int i=n;i;i--){
		for(int j=1;j<=up;j++){
			a[i][j]+=a[i+j][j];
			a[i][j]+=s[i];
		}
	}//a[i][j]��i��ʼ����Ϊj��һֱ�ӵ�iС�ڵ���nΪֹ�ĺ�׺��
	for(int i=n;i;i--){
		for(int j=1;j<=up;j++){
			b[i][j]+=b[i+j][j];
			b[i][j]+=a[i][j];
		}
	}//b[i][j]�Ǵ�i��ʼ����Ϊj��1*s[i],2*s[i+j],3*s[i+2*j]+......�±�((i+k*j)<=n)
	
	
}
