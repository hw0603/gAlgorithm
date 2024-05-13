#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int s;
  cin >> s;

  if (s % 4763 != 0) {
    cout << 0;
    return 0;
  }

  if (s == 0) {
    cout << 1 << '\n' << "0 0" << '\n';
    return 0;
  }

  vector<pair<int, int>> v;
  s /= 4763;
  for (int i = 0; i <= 200; ++i) {
    int a = s - i*508;
    if (i*508 <= s && a % 212 == 0 && a/212 <= 200) {
      v.push_back({i, a/212});
    }
    if (i*508 <= s && a % 305 == 0 && a/305 <= 200) {
      v.push_back({i, a/305});
    }
    a = s - i*108;
    if (i*108 <= s && a % 212 == 0 && a/212 <= 200) {
      v.push_back({i, (s - i*108)/212});
    }
    if (i*108 <= s && a % 305 == 0 && a/305 <= 200) {
      v.push_back({i, (s - i*108)/305});
    }
  }
  sort(v.begin(), v.end());
  cout << v.size() << '\n';
  for (pair<int, int> p : v) {
    cout << p.first << ' ' << p.second << '\n';
  }
}
