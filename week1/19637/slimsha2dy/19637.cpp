#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
string ss[100002];
int ifs[100002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> ss[i] >> ifs[i];
  }

  for (int i = 0; i < m; ++i) {
    int input;
    cin >> input;
    cout << ss[lower_bound(ifs, ifs+n, input) - ifs] << '\n';
  }
  return 0;
}
