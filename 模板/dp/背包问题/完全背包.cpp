#include<bits/stdc++.h>
using namespace std;
int d[1010],n,v[1010],w[1010],V;
int main(){
    cin>>n>>V;
    for(int i=0;i<n;i++){
        cin>>v[i]>>w[i];
    }
    memset(d,0,sizeof d);//���ѱ���װ��������������ֵȫ����ʼΪ0
                            //ֻ��ǡ��װ������������µ����ֵ��ֻ��d[0]��ʼΪ0�������ʼΪ������
    for(int i=0;i<n;i++){
        for(int j=v[i];j<=V;j++){
            d[j]=max(d[j],d[j-v[i]]+w[i]);//j��ǰ����ö��ʱ�õ����ǵ�i���d[j-v[i],�Ӻ���ǰö��ʱ�õ����ǵ�i-1���d[j-v[i]
        }
    }
    cout<<d[V];
}
