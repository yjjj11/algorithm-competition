
#include <bits/stdc++.h>
using namespace std;
const int N = 50010;

int n,a[1005];
int f[N];
int main()
{
    //input
    int i=1,res=0;
    while(cin>>a[i])i++;
    n=i-1;
    for (int i = n; i; -- i)
    {
        f[i]=1;
        for (int j = n; j > i; -- j)
        {
            if (a[i]>=a[j]) f[i] = max(f[i], f[j] +1);
        }
        res=max(res,f[i]);
    }
    cout<<res<<"\n";
    int p[1005],len=0;
    memset(p,0x3f,sizeof p);
    for(int i=1;i<=n;i++){
        int j=1;
        while(a[i]>p[j])j++;
        if(j>len){
            len++;
            p[len]=a[i];
        }
        else p[j]=a[i];
        
    }
    cout<<len;
    return 0;
}
