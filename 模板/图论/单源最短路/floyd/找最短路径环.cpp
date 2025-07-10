#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std ;

const int N = 110 , M = 10010 , INF = 0x3f3f3f3f ;


typedef long long LL ;
int g[N][N] , d[N][N] ;
int pos[N][N] ; //��¼��ǰ״̬���ĸ���ת�ƹ���
vector<int> path ;
int n , m ;

//ȷ��˳����ȷ
void dfs(int i , int j )    //i->j֮���·�����i��j֮�䲻����i��j�ĵ�·
{
    int k = pos[i][j] ;

    if( k == 0 )    return ;    //�����0��˵��i,j֮�䲻������i��j֮���������

    dfs(i , k); //i->newk
    path.push_back(k);  //k
    dfs(k , j); //newk->j

}

void get_path(int i , int j , int k )
{
    path.clear() ;
    path.push_back(k);  //�߽�
    path.push_back(i);
    dfs(i , j) ;    //k->i->j->k
    path.push_back(j);
}

int main()
{
    cin >> n >> m ; 

    memset(g , 0x3f ,sizeof g) ;
    for(int i = 0 ; i <= n ; i++ )  g[i][i] = 0 ;

    int a , b , c ;
    for(int i = 0 ; i < m ; i++ )
    {
        cin >> a >> b >> c ;
        g[a][b] = g[b][a] = min(g[a][b] , c) ;
    }

    memcpy(d , g , sizeof d );  //ԭͼ
    long long res = INF ;

    for(int k = 1 ; k <= n ; k++ )
    {
        //���ٰ���������Ļ��������ĵ���������k
        for(int i = 1 ; i < k ; i++ )  //���ٰ��������㣬i��j��k���غ�
            for(int j = i + 1 ; j < k ; j ++ )
            if(res > (LL)g[i][j] + d[i][k] + d[k][j] )
            {
                res = g[i][j] + d[i][k] + d[k][j] ;
                get_path(i , j , k) ;
            }

        for(int i = 1 ; i <= n ; i++ )
            for(int j = 1 ; j <= n ; j++ )
                if(g[i][j] > g[i][k] + g[k][j])
                {
                    g[i][j] = g[i][k] + g[k][j] ;
                    pos[i][j] = k ; 
                }
    }

    if(res == INF)  
        cout << "No solution." << endl;
    else
    {
        for(auto x : path)
            cout << x << ' ' ;
        cout << endl;
    }

    return 0;
}
