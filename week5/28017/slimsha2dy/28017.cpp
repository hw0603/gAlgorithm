#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int d[503][503];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int input;
      cin >> input;
      d[i][j] = 2147483647;
      for (int k = 1; k <= m; ++k) {
        if (k == j) continue;
        d[i][j] = min(d[i][j], d[i-1][k] + input);
      }
    }
  }
  cout << *min_element(d[n]+1, d[n]+m+1);
}
