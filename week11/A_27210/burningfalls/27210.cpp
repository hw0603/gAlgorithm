#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

int main() {
    FASTIO;
    int N;
    cin >> N;
    vector<int> v(N + 2, 0);
    for(int i = 1; i <= N; i++) {
        cin >> v[i];
        if (v[i] == 2) {
            v[i] = -1;
        }
    }
    
    vector<int> dp(N + 2, 0);
    int ans = 0;
    
    for(int i = 1; i <= N; i++) {
        dp[i] = max(v[i], dp[i - 1] + v[i]);
        ans = max(ans, abs(dp[i]));
    }
    
    for(int i = 1; i <= N; i++) {
        dp[i] = min(v[i], dp[i - 1] + v[i]);
        ans = max(ans, abs(dp[i]));
    }
    
    cout << ans << "\n";

    return 0;
}
