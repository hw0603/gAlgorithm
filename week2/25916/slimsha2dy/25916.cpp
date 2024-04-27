#include <iostream>

using namespace std;

int n, m;
int arr[500002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> arr[i];
  int en = 0;
  int sum = arr[0];
  int max = 0;
  for (int st = 0; st < n; ++st) {
    if (st) sum -= arr[st-1];
    while (en < n && sum <= m) {
      if (max < sum) max = sum;
      en++;
      sum += arr[en];
    }
    if (en == n) break;
  }
  cout << max;
}
