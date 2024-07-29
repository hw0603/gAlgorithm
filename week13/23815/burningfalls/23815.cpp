#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

int Calc(int x, string s) {
    if (x == 0) {
        return 0;
    }
    int y = s[1] - '0';
    int ans = 0;
    if (s[0] == '+') {
        ans = x + y;
    } else if (s[0] == '-') {
        ans = x - y;
    } else if (s[0] == '*') {
        ans = x * y;
    } else if (s[0] == '/') {
        ans = x / y;
    }
    return max(0, ans);
}

int main() {
    FASTIO;
    int N;
    cin >> N;
    vector<vector<int>> dp(N + 1, vector<int>(2));
    dp[0][0] = 1;
    dp[0][1] = 0;
    for(int i = 1; i <= N; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        dp[i][0] = max(Calc(dp[i - 1][0], s1), Calc(dp[i - 1][0], s2));
        dp[i][1] = max({Calc(dp[i - 1][1], s1), Calc(dp[i - 1][1], s2), dp[i - 1][0]});
    }
    
    int ans = max(dp[N][0], dp[N][1]);
    if (ans == 0) {
        cout << "ddong game";
    } else if (ans != 0) {
        cout << ans;
    }
    cout << "\n";
    
    return 0;
}




