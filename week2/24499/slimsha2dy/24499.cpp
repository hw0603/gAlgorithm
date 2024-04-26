#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int arr[100002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> arr[i];
  int total = 0;
  for (int i = 0; i < k; ++i) {
    total += arr[i];
  }
  int high = total;
  for (int i = 0; i < n-1; ++i) {
    total -= arr[i];
    if (i+k >= n) total += arr[(i+k) % n];
    else total += arr[i+k];
    high = max(total, high);
  }

  cout << high;
}
