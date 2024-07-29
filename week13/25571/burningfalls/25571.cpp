#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define ll long long

int main() {
    FASTIO;
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        vector<int> v(N);
        for(int i = 0; i < N; i++) {
            cin >> v[i];
        }
        
        ll ans = 0;
        ll cnt = 1;
        for(int i = 1; i < N; i++) {
            bool flag = false;
            flag |= (i % 2 == 1 && v[i - 1] < v[i]);
            flag |= (i % 2 == 0 && v[i - 1] > v[i]);
            if (flag) {
                cnt++;
            } else if (!flag) {
                ans += (cnt * (cnt - 1)) / 2;
                cnt = 1;
            }
        }
        ans += (cnt * (cnt - 1)) / 2;
        
        cnt = 1;
        for(int i = 1; i < N; i++) {
            bool flag = false;
            flag |= (i % 2 == 1 && v[i - 1] > v[i]);
            flag |= (i % 2 == 0 && v[i - 1] < v[i]);
            if (flag) {
                cnt++;
            } else if (!flag) {
                ans += (cnt * (cnt - 1)) / 2;
                cnt = 1;
            }
        }
        ans += (cnt * (cnt - 1)) / 2;
        
        cout << ans << "\n";
    }
    
    return 0;
}




