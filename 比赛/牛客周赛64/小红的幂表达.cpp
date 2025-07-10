#include<bits/stdc++.h>
using namespace std;
int main(){
    int x; cin >> x;
    cout << x;
    cout << endl;
    for(int i = x; i >= 1; i--){
        int l = 1, r = x;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(pow(i, mid) == x){
                cout << "=" << i << "^" << mid << endl;
                break;
            } else if(pow(i, mid) > x){
                r = mid - 1;
            } else{
                l = mid + 1;
            }
        }
    }
}