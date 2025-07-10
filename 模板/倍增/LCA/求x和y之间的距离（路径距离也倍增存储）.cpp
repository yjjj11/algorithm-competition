1 #include<iostream>
 2 #include<cstdio>
 3 #include<cstring>
 4 #include<cctype>
 5 #define re register
 6 using namespace std;
 7 char gc(){
 8     static char buf[100000],*p1=buf,*p2=buf;
 9     return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
10 }
11 void read(int &x){
12     char c=getchar();x=0;
13     while(!isdigit(c)) c=getchar();
14     while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
15 }
16 void swap(int &a,int &b){a^=b;b^=a;a^=b;}
17 //-----优化------
18 #define N 1002
19 int n,Q,d[N],fa[11][N],fv[11][N];
20 int cnt,hd[N],nxt[N<<1],ed[N],poi[N<<1],val[N<<1];
21 void adde(int x,int y,int v){
22     nxt[ed[x]]=++cnt; hd[x]=hd[x]?hd[x]:cnt;
23     ed[x]=cnt; poi[cnt]=y; val[cnt]=v;
24 }
25 void dfs(int x,int ffa){
26     fa[0][x]=ffa; d[x]=d[ffa]+1;
27     for(int i=1;(1<<i)<=d[x];++i){
28         fa[i][x]=fa[i-1][fa[i-1][x]];
29         fv[i][x]=fv[i-1][x]+fv[i-1][fa[i-1][x]];//路径和预处理
30     }
31     for(int i=hd[x];i;i=nxt[i])
32         if(poi[i]!=ffa){
33             fv[0][poi[i]]=val[i];
34             dfs(poi[i],x);
35         }
36 }
37 int ask(int x,int y){
38     if(d[x]<d[y]) swap(x,y);
39     int res=0;
40     for(int i=10;i>=0;--i)
41         if(d[fa[i][x]]>=d[y])
42             res+=fv[i][x],x=fa[i][x];
43     if(x==y) return res;
44     for(int i=10;i>=0;--i)
45         if(fa[i][x]!=fa[i][y]){
46             res+=fv[i][x]+fv[i][y];
47             x=fa[i][x]; y=fa[i][y];
48         }
49     return res+fv[0][x]+fv[0][y];//记得最后还要加一次
50 }
51 int main(){
52 //    freopen("chino.in","r",stdin);
53     read(n);read(Q); int q1,q2,q3;
54     for(re int i=1;i<n;++i){
55         read(q1);read(q2);read(q3);
56         adde(q1,q2,q3); adde(q2,q1,q3);
57     }dfs(1,0);
58     for(re int i=1;i<=Q;++i){
59         read(q1); read(q2);
60         printf("%d\n",ask(q1,q2));
61     }return 0;
62 }
