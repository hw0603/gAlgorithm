#include <iostream>

using namespace std;

int n;
int arr[101010];
int dp[101010];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <=n; ++i) cin >> arr[i];

  int maxi = 0;
  int mini = 0;
  for (int i = 1; i <=n; ++i) {
    dp[i] = dp[i-1];
    if (arr[i] == 1) dp[i]++;
    else dp[i]--;
    maxi = max(dp[i], maxi);
    mini = min(dp[i], mini);
  }

  cout << abs(maxi-mini);
}
