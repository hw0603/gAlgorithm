#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); ios_base::sync_with_stdio(0);

int main() {
    FASTIO;
    string s;
    cin >> s;
    int len = (int)s.size();
    vector<vector<int>> dp(len + 1, vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = 2e9;
    
    for(int i = 1; i <= len; i++) {
        if (s[i - 1] >= 'A' && s[i - 1] <= 'Z') {
            dp[i][0] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 2);
            dp[i][1] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 1);
        } else if (s[i - 1] >= 'a' && s[i - 1] <= 'z') {
            dp[i][0] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 2);
            dp[i][1] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 2);
        }
    }
    
    cout << min(dp[len][0], dp[len][1]) << "\n";
    
    return 0;
}






