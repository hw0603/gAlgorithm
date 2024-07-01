#include <iostream>
#include <algorithm>

using namespace std;

int n, m, r;
int mal[2002], git[40002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> r;
  for (int i = 0; i < n; ++i) cin >> mal[i]; 
  for (int i = 0; i < m; ++i) cin >> git[i];
  sort(mal, mal+n);

  double res = 0;
  for (int i = 0; i < m; ++i) {
    int st = 0;
    int en = 0;
    while (en < n) {
      double tmp = (mal[en] - mal[st]) * git[i];
      tmp /= 2;
      if (tmp <= r) {
        res = max(res, tmp);
        en++;
      }
      else {
        st++;
      };
    }
  }
  if (res == 0) {
    cout << -1;
    return 0;
  }
  printf("%.1f", res);
}
