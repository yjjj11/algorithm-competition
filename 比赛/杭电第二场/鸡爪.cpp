#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n<=3)for(int i=2;i<=4;i++)cout<<1<<" "<<i<<"\n";
        else if(n<=6){
            for(int i=2;i<=5;i++)cout<<1<<" "<<i<<"\n";
            cout<<"2 3\n";
            cout<<"2 4\n";
        }
        else{
            for(int i=2;i<=n/3+3;i++)cout<<1<<" "<<i<<"\n";
            if(n%3==1)cout<<1<<" "<<n/3+4<<"\n";
            if(n%3==2)cout<<1<<" "<<n/3+5<<"\n";
            for(int i=3;i<=n/3+2;i++)cout<<2<<" "<<i<<"\n";
            for(int i=4;i<=n/3+1;i++)cout<<3<<" "<<i<<"\n";
        }
    }
}
