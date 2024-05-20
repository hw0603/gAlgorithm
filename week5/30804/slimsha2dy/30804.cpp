#include <iostream>

using namespace std;

int arr[200003];
int dp[10][10][200003];
int n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }

  int res = 0;
  for (int i = 1; i <= n; ++i) {
    int tmp = arr[i];
    for (int j = 1; j < 10; ++j) {
      if (j == tmp) continue;
      // dp[값1][값2][몇번째] = 몇번째까지 봤을 때 두 값이 연속해서 몇번 나왔는지
      dp[tmp][j][i] = dp[tmp][j][i-1] + 1;
      dp[j][tmp][i] = dp[j][tmp][i-1] + 1;
      res = max({res, dp[tmp][j][i], dp[j][tmp][i]});
    }
  }
  cout << res;
}
