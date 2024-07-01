#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(0); cout.tie(0);
#define INF 2e9

int main() {
    FASTIO;
    int A, B, C, K;
    cin >> A >> B >> C >> K;
    
    vector<vector<int>> dp(K + 1, vector<int>(4, INF));
    dp[0][0] = 0;
    for(int i = 1; i <= K; i++) {
        for(int j = 0; j < 4; j++) {
            if (i - A >= 0) {
                dp[i][j] = min(dp[i][j], dp[i - A][(j + 1) % 4]);
            }
            if (i - B >= 0) {
                dp[i][j] = min(dp[i][j], dp[i - B][(j + 3) % 4]);
            }
            if (i - C >= 0) {
                dp[i][j] = min(dp[i][j], dp[i - C][(j + 2) % 4]);
            }
            if (dp[i][j] != INF) {
                dp[i][j] += 1;
            }
        }
    }
    
    cout << (dp[K][0] == INF ? -1 : dp[K][0]) << "\n";
    
    return 0;
}


