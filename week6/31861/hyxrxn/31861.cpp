#include <iostream>

using namespace std;

long long dp[27][1001] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    long long answer = 0;
    if (n == 0) {
        answer = 1;
        for (int i = 0; i < m; i++) {
            answer *= 26;
            answer %= 1000000007;
        }
        cout << answer;
        return 0;
    }

    for (int i = 1; i <= 26 - n; i++) {
        dp[i][1] = 1;
        dp[27 - i][1] = 1;
    }

    for (int i = 2; i <= m; i++) { // i번째 위치
        for (int j = 1; j <= 26; j++) { // 무슨 문자
            for (int k = j - n; k >= 1; k--) {
                dp[j][i] += dp[k][i - 1];
            }
            for (int k = j + n; k <= 26; k++) {
                dp[j][i] += dp[k][i - 1];
            }
            dp[j][i] %= 1000000007;
//            cout << "dp[" << j << "][" << i << "] = " << dp[j][i] << endl;
        }
    }

    for (int i = 1; i <= 26; i++) {
        answer += dp[i][m];
        answer %= 1000000007;
    }

    cout << answer;

    return 0;
}