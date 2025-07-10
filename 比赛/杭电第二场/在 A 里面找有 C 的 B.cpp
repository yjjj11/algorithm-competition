#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5;
int tr[N][26], ne[N], idx, cnt[N];
vector<int>id[N];
void insert(string s, int x) {
    int p = 0;
    for (int i = 0; s[i]; i++) {
        int u = s[i] - 'a';
        if (!tr[p][u]) tr[p][u] = ++idx;
        p = tr[p][u];
    }
    id[p].push_back(x);
}

void build() {
    queue<int> q;
    for (int i = 0; i < 26; i++) if (tr[0][i]) q.push(tr[0][i]);

    while (q.size()) {
        int t = q.front();
        q.pop();
        for (int i = 0; i < 26; i++) {
            int u = tr[t][i];
            if (!u) tr[t][i] = tr[ne[t]][i];
            else {
                ne[u] = tr[ne[t]][i];
                q.push(u);
            }
        }
    }
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        idx = 0;
        memset(tr, 0, sizeof tr);
        memset(ne, 0, sizeof ne);
        memset(id, 0, sizeof id);
        int n,lenc,nee[5*N];
        cin>>n;
        string a, c;
        cin >> a >> c;
        lenc=c.size();
        c="0"+c;
        for(int j=0,i=2;i<=lenc;i++){
            while(j&&c[j+1]!=c[i])j=nee[j];
            if(c[j+1]==c[i])j++;
            nee[i]=j;
        }
        for (int k = 1; k <= n; k++) {
            string b, bb;
            cin >> b >> bb;
            int lenb=bb.size();
            bb="0"+bb;
            for(int j=0,i=1;i<=lenb;i++){
                while(j&&c[j+1]!=bb[i])j=nee[j];
                if(c[j+1]==bb[i])j++;
                if(j==lenc){
                    insert(b, k);
                    break;
                }
            }
        }
        build();
        set<int>ans;
        for (int i = 0, p = 0; a[i]; i++) {
            int u = a[i] - 'a';
            p = tr[p][u];
            int j=p;
            while(j){
                for(auto t : id[j])ans.insert(t);
                id[j].clear();
                j=ne[j];
            }
            
        }
        for (auto j : ans) {
            cout<<j<<" ";
        }
        cout << "\n";
        ans.clear();
    }
}
