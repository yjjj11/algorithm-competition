#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a,res;
        cin>>a;
        res = a;
        for(int i=2;i<=a/i;i++)
        {
            if(a%i==0)
            {
                while(a%i==0)
                    a/=i;
                res = res / i*(i-1);
            }
        }
        if(a>1) res = res /a*(a-1);
        cout<<res<<endl;
    }
    return 0;
}
