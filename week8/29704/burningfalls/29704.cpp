#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    vector<pair<int, int>> v(N);
    int sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
        sum += v[i].second;
    }
    
    vector<int> dp(T + 1, -1);
    dp[0] = 0;
    for(int i = 0; i < N; i++) {
        int d = v[i].first;
        int m = v[i].second;
        for(int j = T; j >= d; j--) {
            if (dp[j - d] == -1) continue;
            dp[j] = max(dp[j], dp[j - d] + m);
        }
    }
    
    int maxi = 0;
    for(int i = 0; i <= T; i++) {
        maxi = max(maxi, dp[i]);
    }
    
    cout << sum - maxi << "\n";
    
    return 0;
}

