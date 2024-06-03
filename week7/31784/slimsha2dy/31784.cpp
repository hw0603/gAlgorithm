#include <iostream>

using namespace std;

int n, m;
string arr;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  cin >> arr;

  for (int i = 0; i < n; ++i) {
    if (arr[i] == 'A') continue;
    int toSum = 'Z' - arr[i] + 1;
    if (toSum <= m) {
      m -= toSum;
      arr[i] = 'A';
    }
  }
  if (m > 0) {
    m %= 26;
    arr[n-1] += m;
    if (arr[n-1] > 'Z') arr[n-1] = arr[n-1] - 'Z' + 'A';
  }

  for (int i = 0; i < n; ++i) cout << arr[i];
}
