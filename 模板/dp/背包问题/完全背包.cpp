#include<bits/stdc++.h>
using namespace std;
int d[1010],n,v[1010],w[1010],V;
int main(){
    cin>>n>>V;
    for(int i=0;i<n;i++){
        cin>>v[i]>>w[i];
    }
    memset(d,0,sizeof d);//不把背包装满的情况下求最大值全部初始为0
                            //只求恰好装满背包的情况下的最大值，只将d[0]初始为0，其余初始为负无穷
    for(int i=0;i<n;i++){
        for(int j=v[i];j<=V;j++){
            d[j]=max(d[j],d[j-v[i]]+w[i]);//j从前往后枚举时得到的是第i层的d[j-v[i],从后往前枚举时得到的是第i-1层的d[j-v[i]
        }
    }
    cout<<d[V];
}
