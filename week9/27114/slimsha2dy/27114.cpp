#include <iostream>
#include <algorithm>

using namespace std;

int k;
int dir[3] = {1, 3, 2};
int eng[3];
int dp[1000002][4];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for (int i = 0; i < 3; ++i) cin >> eng[i];
  cin >> k;

  for (int i = 0; i <=k; ++i) fill(dp[i], dp[i]+4, 2000000);

  dp[0][0] = 0;
  for (int i = 1; i <=k; ++i) {
    for (int j = 0; j < 4; ++j) {
      for (int x = 0; x < 3; ++x) {
        if (i < eng[x]) continue;
        dp[i][j] = min(dp[i-eng[x]][(j+dir[x])%4]+1, dp[i][j]);
      }
    }
  }

  if (dp[k][0] == 2000000) cout << -1;
  else cout << dp[k][0];
}
