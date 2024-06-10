#include <iostream>

using namespace std;

int n, m;
pair<int, int> arr[1002];
int dp[1002][1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  int total = 0;
  for (int i = 1; i <= n; ++i) {
    int day, don;
    cin >> day >> don;
    total += don;
    for (int j = 1; j <= m; ++j) {
      if (j < day) dp[i][j] = dp[i-1][j];
      else dp[i][j] = max(dp[i-1][j-day] + don, dp[i-1][j]);
    }
  }
  cout << total - dp[n][m];
}
