// ����С��������ͳ�Ʊ��ÿ�����Ƿ������ߣ�ͬʱ����С������������Ȩֵ֮��Ϊsum

// Ԥ���������������������ı�Ȩ���ֵdist1[a][b]�ͳ��ȴδ�dist2[a][b] ����������·��Ψһ��dfs��

// ����ö�����з�MST��t����t����a��b,ȨΪw����Ȼa��b��MST�С�
//     ������t�滻a-b��·��������һ����A��t��Ȩw >= A�������w < A,ֱ�ӻ��߾��ܵõ���С����������ì���ˣ�
//     ���w > A,�滻����Ȩֵ��sum + w - dist1[a][b] 
//     ���� w = A �������滻����õ����ϸ��С��������Ȩֵ��MST��ȣ�
//     w = A��w > �δ�ֵB �滻����Ȩֵ��sum + w - dist2[a][b] 

//  */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 510, M = 10010;
typedef long long LL;

struct Edge{
    int a, b, w;
    bool f = false;
    bool operator < (const Edge & A) const{
        return w < A.w;
    }
}edge[M];

int h[N], e[N * 2], ne[N * 2], w[N * 2], idx; // ������ 2 * N
int cnt;
int n, m;
int dist1[N][N], dist2[N][N];// ��С�ʹ�С
int p[N];
void add(int a,int b,int c){
    e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx ++;
}
int find(int x){
    return x == p[x] ? x : p[x] = find(p[x]);
}

//dfs����ͼ���ɣ���¼���ڵ��ֹ����
void dfs(int u, int fa, int maxd1, int maxd2, int d1[], int d2[]){
    d1[u] = maxd1, d2[u] = maxd2;
    for (int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if (j != fa){ //��������
            int td1 = maxd1,  td2 = maxd2;
            if (w[i] > td1) td2 = td1, td1 = w[i];
            else if (w[i] < td1 && w[i] > td2) td2 = w[i];
            dfs(j, u, td1, td2, d1, d2);
        }
    }
}


int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    ;
    for(int i = 0; i < m; ++ i){
        int a, b, w;
        cin >> a >> b >> w;
        edge[i] = {a, b, w}; 
    }

    sort(edge, edge + m);
    for(int i = 1; i <= n; ++ i)p[i] = i;
    LL sum = 0;

    for(int i = 0; i < m; ++ i){
        int a = edge[i].a, b = edge[i].b, w = edge[i].w;
        int pa = find(a), pb = find(b); 
        if (pa != pb)
        {
            p[pa] = pb;
            sum += w;
            add(a, b, w), add(b, a, w);//! �ϲ����ϣ����ӱ��ǽڵ�֮��ӱ�
            edge[i].f = true;
        }
    }

    for(int i = 1; i <= n; ++ i)dfs(i, -1, -1e9,-1e9, dist1[i],dist2[i]);// �������������·

    LL res = 1e18;

    for(int i = 0; i < m; ++ i){ 
        int a = edge[i].a, b = edge[i].b, w = edge[i].w;

        if(!edge[i].f){// ����ÿ���ⲿ�߳����滻
            LL t = 1e18;
            if(w > dist1[a][b]){
                t = sum + w - dist1[a][b];
            }else if( w > dist2[a][b]){ // w���Ǵ��ھ��ǵ���
                t = sum + w - dist2[a][b];
            }
            res = min(res, t);
        }
    }
    cout << res << endl;


    return 0;
}
