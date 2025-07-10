#include<iostream>
#include<cstring>
#include<algorithm>
#include<deque> //˫�˶��е�ͷ�ļ�����·�����ڵ�����¿����Ƴ�k���ߣ�ʹʣ���Ȩ���ֵ��С

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int N = 1002;//�������߳�

bool g[N][N];   //��¼λ�����Ƿ����ϰ���У�true  �ޣ�flase��
bool st[N][N];  //�ж��Ƿ��߹��˴����߹���true  �ޣ�false��
int dist[N][N];//���·������

int bfs(int sx, int sy){
    
    deque<PII> q;//����˫�˶���
    q.push_back({sx, sy});//���ӵ�˫�˶���
    memset(dist, 0x3f, sizeof dist);//�Ѿ����ʼ���������� 
    dist[sx][sy] = 0;
    
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};//˳����������
     
    while(q.size()){//�����в���
        auto t = q.front();//ȡ����ͷԪ��
        q.pop_front();//ɾ����ͷԪ�ء�
        
        if(st[t.x][t.y])continue;//�жϵ�ǰ���Ƿ��ѹ� 
        st[t.x][t.y] = true;//�жϵ�ǰ���Ƿ��ѹ� 
        
        if(!t.x && !t.y)break;//�жϵ�ǰ���Ƿ��ѹ� 
        
        for(int i = 0; i < 4; i++){
            int x = t.x + dx[i], y = t.y + dy[i];//��ǰ��������
            if(x >= 0 && x < N && y >= 0 &&y < N){
                int w = g[x][y]==1 ?1:0;//������ϰ��Ȩֵ��Ϊ1 ��������Ϊ0
                //int w = 0;
                //if (g[x][y]) w = 1;
                if(dist[x][y] > dist[t.x][t.y] + w){//��������ܱ������ұ�ԭ�о������
                    dist[x][y] = dist[t.x][t.y] + w;//����Ȩֵ
                    if(!w) q.push_front({x,y});//�ӵ���ͷ
                    else q.push_back({x, y});//�ӵ���β
                }
            }
        }
    }
    
    return dist[0][0];
}


int main(){
    int n, sx, sy;//n���ϰ���������sx��sy�����
    scanf("%d%d%d", &n, &sx, &sy);
    while(n--){
        int x, y;
        scanf("%d%d", &x, &y);//�����ϰ��������
        g[x][y] = true;
    }
    printf("%d\n",bfs(sx,sy));//�������ԭ����̾��� 
    
    return 0;
}
