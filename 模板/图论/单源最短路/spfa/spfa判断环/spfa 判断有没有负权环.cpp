#include<bits/stdc++.h>
using namespace std;
int dis[150010],cnt[150010],e[150010],h[150010],ne[150010],w[150010],n,m,idx;
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
bool st[150010];
void spfa(){
    memset(dis,0x3f,sizeof dis);
    queue<int>q;
    for(int i=1;i<=n;i++){
        st[i]=true;
        q.push(i);
    }//��ȷ�����Ǹ���㿪ʼ�����ߵ���Ȩ�ߣ����Խ�ÿ�����㶼�ӽ�ȥ
    while(q.size()){
        int u=q.front();
        q.pop();
        st[u]=false;
        for(int i=h[u];i!=-1;i=ne[i]){
            int j=e[i];
            if(dis[j]>dis[u]+w[i]){
                dis[j]=dis[u]+w[i];
                cnt[j]=cnt[u]+1;//�����ߵ��õ���С·���Ĳ�����
                if(cnt[j]>=n){//ÿ��ѭ��һȦ�����С�����������n-1����Сֵ����û�й̶��Ļ�˵�����ڸ���
                    cout<<"Yes";
                    return ;
                }//��Ϊ�����ڸ�Ȩ�ߵ�ͼֻ��Ҫn-1�ξͿ��Ը�����
                if(!st[j]){
                    q.push(j);
                    st[j]=true;
                }
            }
        }
    }
    cout<<"No";
}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    
    for(int i=0;i<m;i++){
        int a,b,s;
        cin>>a>>b>>s;
        add(a,b,s);
        
    }
    spfa();
}
