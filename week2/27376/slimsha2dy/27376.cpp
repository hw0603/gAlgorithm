#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int n, k;
vector<tuple<int, int, int>> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  for (int i = 0; i < k; ++i) {
    int x, t, s;
    cin >> x >> t >> s;
    v.push_back({x, t, s});
  }
  sort(v.begin(), v.end());

  int res = 0;
  int tmp = 0;
  for (tuple<int, int, int> tp : v) {
    int x, t, s;
    tie(x, t, s) = tp;
    res += x - tmp;
    tmp = x;
    if (res < s) res = s;
    if (((res - s) / t) % 2 == 1) {
      res += t;
      res -= (res - s) % t;
    }
  }
  res += n - tmp;
  cout << res;
}
