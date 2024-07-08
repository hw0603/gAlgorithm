#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100002];
long long p, q, r, s;
long long total;

bool func(int k) {
  int* low = lower_bound(arr, arr+n, k);
  int* high = upper_bound(arr, arr+n, k + r);

  long long l = low - arr;
  long long r = arr+n - high;
  long long tmp = total + l*q - r*p;

  return tmp >= s;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    total += arr[i];
  }
  cin >> p >> q >> r >> s;

  sort(arr, arr+n);

  long long st = 1;
  long long en = 200000;
  long long ans = -1;
  while (st <= en) {
    int mid = (st + en) / 2;
    if (func(mid)) {
      ans = mid;
      en = mid - 1;
    }
    else st = mid + 1;
  }

  /*
  for (int i = 1; i < 200000; ++i) {
    if (func(i)) {
      cout << i;
      return 0;
    }
  }
  */

  cout << ans;
}
