#include <iostream>

using namespace std;

int n;
int dp[101010][2];

int func(int i, string s) {
  char c = s[0];
  int num = stoi(s.substr(1, s.size()));
  if (c == '+') return i + num;
  if (c == '-') return i - num;
  if (c == '*') return i * num;
  return i / num;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  cin >> n;
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    string a, b;
    cin >> a >> b;

    if (dp[i-1][0] > 0) {
      dp[i][0] = max(func(dp[i-1][0], a), func(dp[i-1][0], b));
      dp[i][1] = dp[i-1][0];
    }
    if (dp[i-1][1] > 0) dp[i][1] = max({dp[i][1], func(dp[i-1][1], a), func(dp[i-1][1], b)});
  }
  if (dp[n][0] <= 0 && dp[n][1] <= 0) cout << "ddong game";
  else cout << max(dp[n][0], dp[n][1]);
}
