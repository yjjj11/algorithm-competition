#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

//这题是一道线性代数问题
//求解一个向量组的秩(最大无关向量组的向量个数)
//但是代码写起来就是一个模拟筛的过程
//从小到大，先查看当前数有没有被晒掉，
//1)如果没有就把它加入到最大无关向量组中，并把他以及他和此前的硬币的线性组合都筛掉
//2)如果有就不理会
//即就是在完全背包求方案数的过程中，统计那些初始没有方案数的物品
//这样就变成一个完全背包问题了

const int N = 110, M = 25010;
int n;
int v[N];
bool f[M];

int main()
{
    int T = 1;
    cin >> T;
    while (T -- )
    {
        cin >> n;
        for (int i = 1; i <= n; ++ i) cin >> v[i];
        sort(v + 1, v + n + 1);//排序的原因见之前的分析

        //我们只需统计所有物品的体积是否能被其他的线性表出
        //因此背包的体积只需设置为最大的物品体积即可
        //res用来记录最大无关向量组的个数
        int m = v[n], res = 0;
        memset(f, 0, sizeof f);
        f[0] = true;    //状态的初值
        for (int i = 1; i <= n; ++ i)
        {
            //如果当前物品体积被之前的物品组合线性筛掉了，则它是无效的
            if (f[v[i]]) continue;
            //如果没有被筛掉，则把它加入最大无关向量组
            res ++ ;
            //筛掉当前最大无关向量组能线性表示的体积
            for (int j = v[i]; j <= m; ++ j)
            {
                f[j] |= f[j - v[i]];
            }
        }
        //输出最大无关向量组的向量个数
        cout << res << endl;
    }
    return 0;
}
