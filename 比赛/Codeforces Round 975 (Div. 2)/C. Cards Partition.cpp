#include<bits/stdc++.h>
int T,n;
long long m,a,v,s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%lld",&n,&m);
		s=v=0;
		for(int i=1;i<=n;++i)
			scanf("%lld",&a),v=std::max(v,a),s+=a;
		for(int i=n;i;--i)
			if((s<v*i&&s+m>=v*i)||(s>=v*i&&(i-s%i)%i<=m))
				printf("%d\n",i),i=1;
	}
	return 0;
}