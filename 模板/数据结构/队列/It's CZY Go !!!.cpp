#include <iostream>
#include <queue>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
queue<int> ch[100005];
int cnt[100005];
pair<int, int> cc[100005];
vector<int> v[100005];
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, q;
        cin >> n >> m >> q;
        for(int i = 1; i <= n; i++){
            while(!ch[i].empty()){
                ch[i].pop();
            }
            v[i].clear();
            cc[i].first = 0;
            cc[i].second = 0;
            cnt[i] = 0;
        }
        int flag = 0;
        while(m--){
            char c;
            cin >> c;
            if(c == 'c'){
                for(int i = 1; i <= 3; i++){
                    cin >> c;
                }
                int a;
                cin >> a;
                for(int i = 1; i <= 2; i++){
                    cin >> c;
                }
                int val;
                cin >> val;
                ch[a].push(val);
                v[a].push_back(val);
            }else{
                for(int i = 1; i <= 2; i++){
                    cin >> c;
                }
                int a;
                cin >> a;
                for(int i = 1; i <= 6; i++){
                    cin >> c;
                }
                int num;
                cin >> num;
                if(ch[num].empty()){
                    flag = 1;
                }else{
                    ch[num].pop();
                    cnt[num]++;
                    cc[a] = {num, cnt[num] - 1};
                }
            }
        }
        if(flag){
            cout << "panic\n";
        }else{
            for(int i = 1; i <= n; i++){
                if(cc[i].first == 0){
                    cout << 0 << " ";
                }else{
                    int pos = cc[i].first;
                    cout << v[pos][(cc[i].second + 1ll * (q - 1) * cnt[pos]) % v[pos].size()] << " ";
                }
            }
            cout << "\n";
        }//一次循环出队k次入队p次，vark在第一轮是第3个出队的，则再循环q-1次后，他是第(3+(q-1)*k)%p
        //相当于在一个长度为q*p的队列中找第3+(q-1)*k个数
    }
}
