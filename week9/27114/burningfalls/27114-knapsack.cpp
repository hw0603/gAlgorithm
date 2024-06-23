#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(0); cout.tie(0);
#define INF 2e9

int main() {
    FASTIO;
    int A, B, C, K;
    cin >> A >> B >> C >> K;
    
    vector<int> v = {A * 4, B * 4, C * 2, A + B, A * 2 + C, B * 2 + C};
    vector<int> cnt = {4, 4, 2, 2, 3, 3};
    
    vector<int> dp(K + 1, INF);
    dp[0] = 0;
    for(int i = 0; i < v.size(); i++) {
        for(int j = v[i]; j <= K; j++) {
            if (dp[j - v[i]] != INF) {
                dp[j] = min(dp[j], dp[j - v[i]] + cnt[i]);
            }
        }
    }
    
    cout << (dp[K] == INF ? -1 : dp[K]) << "\n";
    
    return 0;
}


