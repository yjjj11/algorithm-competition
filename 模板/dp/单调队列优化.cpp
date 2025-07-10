#include <bits/stdc++.h>

using namespace std;

int k;      
int n;    
int e;      
int cnt = 0;  
int G[100][100];  
int c[100];      

void input()
{
    int u, v;  
    cin>>n>>k;
    cin>>e;
    memset(G, 0, sizeof(G));

    for(int i = 1; i <= e; ++i)
    {
        cin>>u>>v;
        G[u][v] = G[v][u] = 1;
    }
}

bool isValid(int i)
{
    for(int j = 1; j < i; ++j)
        if(G[i][j] == 1 && c[j] == c[i])
            return false;
    return true;
}

void backtrack(int i)
{
    if(i > n)
    {
        cnt += 1;
        cout<<"方法 "<<cnt<<"  :";
        for(int j = 1; j <= n; ++j)
        {
           cout<<c[j];
        }
        cout<<endl;
        return;
    }
    else
    {
        for(int j = 1; j <= k; ++j)
        {
            c[i] = j;
            if(isValid(i))
                backtrack(i + 1);
            c[i] = 0;
        }
    }
}

void output()
{
   cout<<"一共有 "<<cnt<<" 种绘色方案"<<endl;
}

int main()
{
    input();
    backtrack(1);
    output();
}