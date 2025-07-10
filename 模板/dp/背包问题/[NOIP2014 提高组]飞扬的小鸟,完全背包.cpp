#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=10000+10;
const int maxm=2000+10;
int n,m,p;
int x[maxn],y[maxn];   //iλ�ã�����x[i],�½�y[i] 
int low[maxn],high[maxn];   //iλ����ͨ���ķ�Χ��low[i]-high[i] 
int f[maxn][maxm];   //��(i,j)�����ٵ������ 
bool e[maxn];    //e[i]��ʾiλ����û�йܵ� 
int main() {
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1; i<=n; ++i) scanf("%d%d",&x[i],&y[i]);
    for(int i=1; i<=n; ++i) {
        low[i]=1;
        high[i]=m;
    }
    int a,b,c;
    for(int i=1; i<=p; ++i) {
        scanf("%d%d%d",&a,&b,&c);
        e[a]=1;
        low[a]=b+1;
        high[a]=c-1;
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1; i<=m; ++i) f[0][i]=0;
    for(int i=1; i<=n; ++i) {
        for(int j=x[i]+1; j<=m+x[i]; ++j)//Ҫ��֤j-x[i]�ķ�Χ��1��m����Ϊ��m��Ҳ�ǿ����������ģ��ȴ洢���mʱ��״̬
            f[i][j]=min(f[i-1][j-x[i]]+1,f[i][j-x[i]]+1);
        for(int j=m+1; j<=m+x[i]; ++j)//�������ʱ��״̬��ȫ����m
            f[i][m]=min(f[i][m],f[i][j]);
        for(int j=1; j<=m-y[i]; ++j)
            f[i][j]=min(f[i][j],f[i-1][j+y[i]]);
        for(int j=1; j<low[i]; ++j)
            f[i][j]=f[0][0];   //����ͨ��(INF) 
        for(int j=high[i]+1; j<=m; ++j)
            f[i][j]=f[0][0];   //����ͨ��(INF)
    }
    int ans=f[0][0];
    for(int j=1;j<=m;++j) {
        ans=min(ans,f[n][j]);
    }
    if(ans<f[0][0]) printf("1\n%d\n",ans);
    else{
        int i,j;
        for(i=n;i>=1;i--) {
            for(j=1;j<=m;++j) {
                if(f[i][j]<f[0][0]) break;
            }
            if(j<=m) break;
        }
        ans=0;
        for(int j=1;j<=i;++j) {
            if(e[j]) ans++;
        }
        printf("0\n%d\n",ans);
    }
    return 0;
}
