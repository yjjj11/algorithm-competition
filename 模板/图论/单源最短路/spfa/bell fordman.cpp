#include<bits/stdc++.h>
using namespace std;
struct edges{
    int a,b,c;
}edge[10010];
int n,m,k,dis[505],backup[505];//backup���ڱ�����һ�ε�״̬����ֹ����������֤ÿ��k��ѭ���õ�·���������ᳬ����ǰ��i
int bf(){
    for(int i=0;i<k;i++){//������bfs��������
        memcpy(backup,dis,sizeof dis);
        for(int j=0;j<m;j++){//����k��ÿ����
            int a=edge[j].a,b=edge[j].b,c=edge[j].c;
            dis[b]=min(dis[b],backup[a]+c);
        }
    }
    if(dis[n]>=0x3f3f3f3f/2)return 0;//���ܴ��ڸ�Ȩ��
    else return dis[n];
}
int main(){
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edge[i]={a,b,c};//����ÿ���ߵ���Ϣ
    }
    memset(dis,0x3f,sizeof dis);
    dis[1]=0;//�����һ��һ��������
    int t=bf();
    if(!t)cout<<"impossible";//����и�Ȩ��·������·һȦ��Ȩ��С��0
    else cout<<t;
}
