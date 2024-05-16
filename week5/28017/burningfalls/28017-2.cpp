#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); ios_base::sync_with_stdio(0);
#define ll long long

int main() {
    FASTIO;
    int N, M;
    cin >> N >> M;
    vector<vector<ll>> v(N + 1, vector<ll>(M + 1));
    vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, 0));
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> v[i][j];
        }
    }
    
    for(int i = 1; i <= N; i++) {
        ll mini1 = 1e18, mini2 = 1e18;
        for(int j = 1; j <= M; j++) {
            if (dp[i - 1][j] < mini1) {
                mini2 = mini1;
                mini1 = dp[i - 1][j];
            } else if (dp[i - 1][j] < mini2) {
                mini2 = dp[i - 1][j];
            }
        }
        for(int j = 1; j <= M; j++) {
            if (dp[i - 1][j] == mini1) {
                dp[i][j] = mini2 + v[i][j];
            } else {
                dp[i][j] = mini1 + v[i][j];
            }
        }
    }
    
    ll mini = 1e18;
    for(int j = 1; j <= M; j++) {
        mini = min(mini, dp[N][j]);
    }
    cout << mini << "\n";
    
    return 0;
}







