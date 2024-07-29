#include <iostream>

using namespace std;

int t, n;
long long dp[101010];
long long arr[101010];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  dp[0] = 1;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    long long ans = 0;
    long long prev = 0;
    for (int i = 1; i < n; ++i) {
      long long tmp = arr[i] - arr[i-1];
      if (prev * tmp < 0) {
        dp[i] = dp[i-1] + 1;
        prev = tmp;
        continue;
      }
      if (tmp == 0) dp[i] = 1;
      else dp[i] = 2;
      ans += dp[i-1] * (dp[i-1]-1) / 2;
      prev = tmp;
    }
    ans += dp[n-1] * (dp[n-1]-1) / 2;
    cout << ans << '\n';
  }
}
