#include <iostream>

using namespace std;

int n, m;
int board[1003][1003];
long long dp[1003][1003];
pair<int, int> st, en;
int int_min = -1050000000;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i <= n; ++i) fill(dp[i], dp[i]+m+1, int_min);
  dp[1][0] = 0; dp[0][1] = 0;
  int a, b, c, d;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cin >> board[i][j];
  cin >> a >> b >> c >> d;
  
  st = {a+1, b+1}; en = {c+1, d+1};
  if (st.first > en.first || st.second > en.second) {
    swap(st, en);
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int fromL = dp[i][j-1] + board[i][j];
      int fromU = dp[i-1][j] + board[i][j];
      if (dp[i-1][j] == int_min && !(i == 1 && j == 1)) fromU = int_min;
      if (dp[i][j-1] == int_min && !(i == 1 && j == 1)) fromL = int_min;
      // 벽이 가로일 때 걸릴 경우
      if (st.first == en.first && st.first == i && st.second <= j && en.second > j)
        dp[i][j] = fromL;
      // 벽이 세로일 때 걸릴 경우
      else if (st.second == en.second && st.second == j && st.first <= i && en.first > i)
        dp[i][j] = fromU;
      else dp[i][j] = max(fromL, fromU);
    }
  }

  if (dp[n][m] == int_min) {
    cout << "Entity";
    return 0;
  }
  cout << dp[n][m];
}
