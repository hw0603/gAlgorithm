#include <iostream>

using namespace std;

int n, m;
int arr[1000002];

bool func(int a) {
  int total = 0;
  for (int i = 0; i < m; ++i) {
    total += arr[i] / a;
  }
  return total >= n;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) cin >> arr[i];
  
  int st = 0;
  int en = 1000000000;

  int mid;
  while (st < en) {
    mid = (st + en + 1) / 2;
    if (func(mid)) st = mid;
    else en = mid - 1;
  }
  cout << en;
}
