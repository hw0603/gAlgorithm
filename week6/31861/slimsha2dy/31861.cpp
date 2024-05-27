#include <iostream>

using namespace std;

int n, m;
int d[1003][28];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  fill(d[0], d[0]+26, 1);
  for (int i = 1; i < m; ++i) {
    for (int j = 0; j < 26; ++j) {
      for (int k = 0; k < 26; ++k) {
        if (j - k > n*-1 && j - k < n) continue;
        d[i][j] = (d[i][j] + d[i-1][k]) % 1000000007;
      }
    }
  }
  int res = 0;
  for (int i = 0; i < 26; ++i) {
    res = (res + d[m-1][i]) % 1000000007;
  }
  cout << res;
}
