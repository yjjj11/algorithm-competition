#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
signed main(){
	int n;
	cin>>n;
	priority_queue<int,vector<int>,greater<int>> qq;//根小
	priority_queue<int,vector<int>,less<int>> qw;//根大
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
        if(qw.size()>qq.size()){
            qq.push(x);
        }
        else qw.push(x);
        if(qq.size()&&qw.size()&&qw.top()>qq.top()){
            int temp=qq.top();
            qq.pop();
            qq.push(qw.top());
            qw.pop();
            qw.push(temp);
        }
		if(i%2==1){
			cout<<qw.top()<<"\n";
		}
	}


}