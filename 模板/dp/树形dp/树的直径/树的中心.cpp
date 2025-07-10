#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=1e5+5,INF=1e9;
int d1[N];int d2[N];int up[N];int p1[N];int p2[N];int h[N];int ne[2*N];int e[2*N];int idx;
int w[N];
int n;
void add(int a,int b,int c){
    e[idx]=b;w[idx]=c;ne[idx]=h[a];h[a]=idx++;
}
int dfs_down(int u,int father){//����u�������·��
    d1[u]=d2[u]=-INF;//�и�Ȩ�ߵ�ʱ��
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==father)continue;
        int dist=dfs_down(j,u)+w[i];
        if(dist>d1[u]){//����һ����͵ڶ�����·��������¼�´Ӹ�·���Ǵ���һ������ȥ��
            d2[u]=d1[u],d1[u]=dist;
            p2[u]=p1[u];p1[u]=j;
        }
        else if(dist > d2[u]){
            d2[u]=dist;
            p2[u]=j;
        }
    }
    if(d1[u]==-INF)d1[u]=d2[u]=0;//���û�иı���õ�ľ��룬��֤���������Ҷ�ڵ�
    return d1[u];
}
void dfs_up(int u,int father){//�ø��ڵ����һ���ӽڵ����ϵ��·��
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==father)continue;
        if(p1[u]==j)up[j]=max(up[u],d2[u])+w[i];
//һ���ӽڵ� j �������·���������ĸ��ڵ� u �������·���������·��ȡ���ֵ
//��������·�������� j �͸�Ϊ�ڶ���������·������Ӧ���룺
        else up[j]=max(up[u],d1[u])+w[i];
        dfs_up(j,u);
    }
}
int main(){
    cin >> n;
    memset(h,-1,sizeof h);
    for(int i=0;i<n-1;i++){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);add(b,a,c);
    }
    dfs_down(1,-1);
    dfs_up(1,-1);
    int res=INF;
    for (int i = 1; i <= n; i ++ ) res = min(res, max(d1[i], up[i]));
    cout << res;
}
