#include<bits/stdc++.h>
using namespace std;

const int N = 20009, INF = 1e9;

struct node
{//node��ű� 
    int to, w;
    //to��ʾ·���յ㣬w��ʾ·��Ȩֵ
    bool operator <(const node &x) const
    {
        if(w == x.w) return to > x.to;
        else return w > x.w;
    }
};

bool v[N];//��¼�ڵ���û�б����� 
int d[N];//��¼ÿһ���ڵ㵽������·
int cnt[N];//��¼ÿ�������ж�����ţ
int n;//��ţ����
int p;//��������
int m;//�ߵĸ���
int ans = INF;//��
vector <node> vec[N];//���
priority_queue <node> q;//���ȶ��� 

void dijkstra(int x)
{
    for (int i = 1; i <= p; ++ i) d[i] = INF, v[i] = false;
    //һ��ʼ�����б߶����������ͨ 
    d[x] = 0;//��㵽�Լ��ľ���Ϊ0 
    q.push((node){x, 0});//������ 
    while (!q.empty())
    {
        node e = q.top(), tmp; q.pop();
        v[e.to] = true;//����㱻���ʹ�
        for (int i = 0; i < vec[e.to].size(); ++ i)
        {
            tmp = vec[e.to][i];
            if (v[tmp.to]) continue;
            if (d[tmp.to] > d[e.to] + tmp.w)
            {
                d[tmp.to] = d[e.to] + tmp.w;//�ɳ�
                q.push((node) {tmp.to, d[tmp.to]});//�����ȶ���
            }   
        }
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> p >> m;
    while (n --)
    {
        int cow; cin >> cow;
        cnt[cow] ++;
    }

    for (int i = 1, u, v, w; i <= m; ++ i)
    {//u����·����㣬v����·���յ㣬w����·������ 
        cin >> u >> v >> w;
        vec[u].push_back((node) {v, w});//���� 
        vec[v].push_back((node) {u, w});//������
        //��Ϊ������ͼ���������� 
    }

    for(int i = 1, sum;i <= p;++ i)
    {
        dijkstra(i); sum = 0;
        bool flag = true;//�ж���ţ�Ƿ����ߵ��� i
        for (int j = 1; j <= p; ++ j)
            if(cnt[j])//�������ţ
            {
                if (d[j] == INF)//�������ţ�߲�������i
                {
                    flag = false;//һ�����Ǵ�
                    break;
                }
                sum += cnt[j] * d[j];//�ۼӴ�
            }
        if (flag) ans = min(ans, sum);
    }

    cout << ans << endl;

    return 0;
}
