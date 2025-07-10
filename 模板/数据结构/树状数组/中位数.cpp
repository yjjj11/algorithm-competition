# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;
 
const int N = 100010;
vector<int> a;
vector<int> b;
 
int t[N]; // 树状数组的t[]
 
int n;
 
int find2(int x) // 找对应的x所对应的下标
{
    int l = 0;
    int r = b.size() - 1;
    while(l < r)
    {
        int mid = (l + r) / 2;
        if(b[mid] >= x)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l + 1; // 使得离散化后的下标从1开始，便于后面树状数组的操作。
}
 
int lowbit(int x)
{
    return x & (-x);
}
 
void add(int x)
{
    for(int i = x ; i <= n ; i += lowbit(i))
    {
        t[i] += 1;
    }
}
 
int sum(int x) // 求1~x的前缀和
{
    int res = 0;
    for(int i = x ; i ; i -= lowbit(i))
    {
        res += t[i];
    }
    return res;
}
 
int main()
{
    scanf("%d",&n);
    for(int i = 1; i <= n ; i++)
    {
        int temp;
        scanf("%d",&temp);
        a.push_back(temp); // a为原数组用于遍历
        b.push_back(temp); // b为离散化后数组，用于离散化。和找值的离散化下标，以及输出值
    }
 
    //离散化
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
 
    for(int i = 0 ; i < a.size() ; i++)
    {
        int idx = find2(a[i]); //找到a[i]离散化后的下标
        //printf("----%d\n",idx);
        add(idx); // 对这个值加 + 1;
        if(i % 2 == 0)
        {
            int l = 1, r = n;
            while(l < r)
            {
                int mid = (l + r) / 2;
                if(sum(mid) >= i / 2 + 1) // 为什么找大于等于 中位数的下标呢？ 因为中位数对应的值可能有多个。也可能只有一个
                {
                    r = mid;
                }
                else
                {
                    l= mid + 1;
                }
            }
            printf("%d\n",b[l - 1]); // 离散化的时候下标 +了 1, 所以输出离散化后对应值时需要 - 1
        }
    }
 
    return 0;
}