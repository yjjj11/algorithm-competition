#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],mn[N],mx[N];
void work(){
	int n;
	cin>>n;
	for(int i=0;i<=n;i++)mn[i]=n,mx[i]=1;
	int mni=n*2,mxi=-n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mn[a[i]]=min(mn[a[i]],i);
		mx[a[i]]=max(mx[a[i]],i);
		mni=min(mni,i+a[i]-1);
		mxi=max(mxi,i-a[i]+1);
	}
	for(int i=1;i<=n;i++){
		mn[i]=min(mn[i],mn[i-1]);
		mx[i]=max(mx[i],mx[i-1]);
		if(mx[i]-mn[i]>=i){
			cout<<"0\n";
			return;
		}
	}
	int ans=max(0,mni-mxi+1);
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}