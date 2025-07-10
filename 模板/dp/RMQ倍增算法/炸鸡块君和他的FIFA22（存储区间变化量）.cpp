#include<bits/stdc++.h>

using namespace std;
const int N = 2e5+10, M = 21;
int n;
int q;
char s[N];
int st[3][N][M];

void init()
{
    for(int j=0; j<M; ++j)
    {
        for(int i=1; i+(1<<j)-1<=n; ++i)
        {
            if(!j)//�����ַ��������ݣ�����Ҫ�� st ������г�ʼ�������ݶ����Լ������������
            {
                if(s[i]=='W')//Ӯ ���
                {
                    st[0][i][j] = st[1][i][j] = st[2][i][j] = 1;
                }
                else if(s[i]=='L')//�� ��� ��������Ҫ���ݷ���ģ 3 �Ľ�����и�ֵ
                {
                    st[0][i][j] = 0;
                    st[1][i][j] = -1;
                    st[2][i][j] = -1;
                }
                else//ƽ�� ��� 
                {
                    st[0][i][j] = st[1][i][j] = st[2][i][j] = 0;
                }
            }
            else
            {
                int mid = i+(1<<(j-1));//���� mid Ϊ���� [i, j] ���е㣬���Ǳ����㷨����·
                for(int k=0; k<3; ++k)//�����Ƴ�����״̬ת�Ʒ���
                {
                    st[k][i][j] = st[k][i][j-1] + st[((k+st[k][i][j-1])%3+3)%3][mid][j-1];
                }
            }
        }
    }
}

int ask(int l, int r, int start)
{
    int len = r - l + 1;
    //������Ϊ len �����仮��Ϊ���� ����Ϊ 2 �����ɴ��� ������
    while(len)
    {
        int k = log(len) / log(2);
        start += st[start%3][l][k];//����ʱ�� ��������һ��Ҫ���� ģ�� ����
        len -= (1<<k), l += (1<<k);
    }
    return start;
}

int main()
{
    cin>>n>>q;
    cin>>s+1;
    
    init();
    
    while(q--)
    {
        int l, r, start;
        scanf("%d%d%d", &l, &r, &start);
        printf("%d\n", ask(l, r, start));
    }
    
    return 0;
}
