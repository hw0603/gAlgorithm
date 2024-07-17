#include <iostream>

using namespace std;

int n;
pair<int, int> arr[1010101];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    arr[i] = {a, b};
  }

  sort(arr, arr+n);
  long long hei = 0;
  long long res = 0;
  for (int i = n-1; i >= 0; --i) {
    long long x = arr[i].first / 2;
    long long y = arr[i].second / 2;

    if (y <= hei) continue;
    res += x * (y - hei);
    hei = y;
  }

  res = res * 4;
  cout << res;
}
