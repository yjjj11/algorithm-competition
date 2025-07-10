#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[10010],ans;
int main(){
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        ans=n-1;
        for(int i=1;i<=n;i++)cin>>a[i];//输入不用说。
        int it=1;
        while(it<n){
        	while(a[it]<a[it+1]&&it<n){
        		it++;
        	}//寻找单调不降子序列的开头（即违反单调不降的数）
        	if(it>=n)break;
        	int tmp=a[it],tmp2=it,cnt=0;
        	while(tmp2<=n){
        		if(a[tmp2]>tmp)cnt++;
        		tmp2++;
        	}//往后看有没有大于它的
        	if(it+cnt-1<ans)ans=it+cnt-1;//取min
        	it++;//记得往后一位，否则会卡死。
        }
        cout<<ans<<endl;//输出答案
    }
  return 0;//华丽的结束
}