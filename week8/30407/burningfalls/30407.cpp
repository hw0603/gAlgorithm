#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(0); cout.tie(0);
#define INF 1e9

int main() {
    FASTIO;
    int N, H, D, K;
    cin >> N;
    cin >> H >> D >> K;
    vector<int> R(N + 1);
    for(int i = 1; i <= N; i++) {
        cin >> R[i];
    }
    
    // 0 -> 사용 안한 상태
    // 1 -> 이미 사용한 상태
    // 2 -> 지금 사용
    vector<vector<vector<int>>> dp(19, vector<vector<int>>(65, vector<int>(3, -INF)));
    dp[0][D][0] = H;
    for(int i = 1; i <= N; i++) {
        for(int j = D; j <= 64; j++) {
            for(int k = 0; k <= 1; k++) {
                if (dp[i - 1][j][k] != -INF) {
                    int health = dp[i - 1][j][k] - max(0, (R[i] - j) / 2);
                    dp[i][j][k] = max(dp[i][j][k], health);
                }
                if (j - K >= 0 && dp[i - 1][j - K][k] != -INF) {
                    int health = dp[i - 1][j - K][k] - max(0, (R[i] - j));
                    dp[i][j][k] = max(dp[i][j][k], health);
                }
            }
            if (dp[i - 1][j][2] != -INF) {
                dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][2]);
            }
            if (j - K >= 0 && dp[i - 1][j - K][2] != -INF) {
                dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - K][2]);
            }
            if (dp[i - 1][j][0] != -INF) {
                int health = dp[i - 1][j][0] - max(0, (R[i] - j));
                dp[i][j][2] = max(dp[i][j][2], health);
            }
        }
    }
    
    int maxi = 0;
    for(int j = D; j <= 64; j++) {
        for(int k = 0; k <= 1; k++) {
            maxi = max(maxi, dp[N][j][k]);
        }
    }
    
    cout << (maxi == 0 ? -1 : maxi) << "\n";
    
    return 0;
}

