#include<bits/stdc++.h>
using namespace std;
int T,n,a[200001],x,ans;
map<int,int>m;//m 统计数字的出现次数 
int main(){
	scanf("%d",&T);
	while(T --){
		m.clear();
		scanf("%d%d",&n,&x);
		ans = n;
		for(int i = 1;i <= n;i ++){
			scanf("%d",&a[i]);
			m[a[i]] ++;
		}
		for(int i = 0;i < n;i ++){
			if(!m[i]){//未出现，找到 mex 终止循环 
				ans = i;
				break;
			}
			if(m[i] > 1){//出现超过一次，执行操作 
				m[i + x] += m[i] - 1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}