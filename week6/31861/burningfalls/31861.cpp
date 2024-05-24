#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); ios_base::sync_with_stdio(0);
#define ll long long
#define MOD 1000000007

int main() {
    FASTIO;
    int N, M;
    cin >> N >> M;
    vector<vector<ll>> dp(M + 1, vector<ll>(26, 1));
    for(int i = 2; i <= M; i++) {
        for(int j = 0; j < 26; j++) {
            ll sum = 0;
            for(int k = 0; k < 26; k++) {
                if (abs(j - k) >= N) {
                    sum = (sum + dp[i - 1][k]) % MOD;
                }
            }
            dp[i][j] = sum;
        }
    }
    
    ll ans = 0;
    for(int i = 0; i < 26; i++) {
        ans = (ans + dp[M][i]) % MOD;
    }
    cout << ans << "\n";
    
    return 0;
}








