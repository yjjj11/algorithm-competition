#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll Random(ll mod)
{
    ll ans = 214;
    return ans = ans * rand()% mod + 1;
}

int main()
{
	srand(time(nullptr));
    ll n;
    
    n = Random(200000);//让数据在1~1000000之间
    cout<<n<<" ";
    n = Random(200000);//让数据在1~1000000之间
	    cout<<n<<"\n";
    

    return 0;
}
