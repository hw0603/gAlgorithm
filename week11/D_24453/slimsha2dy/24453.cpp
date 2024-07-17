#include <iostream>

using namespace std;

int n, m;
int x, y;
int arr[505050];

bool func(int k) {
  if (k >= m) return true;
  int res = 0;
  for (int i = k; i < m+1; ++i) {
    res = max(res, arr[i+1] - arr[i-k] - 1);
  }
  return res >= x;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= m; ++i) cin >> arr[i];
  cin >> x >> y;

  sort(arr, arr+m);
  arr[m+1] = n+1;

  int st = y;
  int en = n+1;
  int ans = 0;
  while (st <= en) {
    int mid = (st + en) / 2;
    if (func(mid)) {
      ans = mid;
      en = mid - 1;
    }
    else st = mid + 1;
  }

  cout << m-ans;
}
