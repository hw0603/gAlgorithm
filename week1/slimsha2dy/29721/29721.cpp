#include <iostream>
#include <set>

using namespace std;

int n, k;
int dx[4] = {2, 0, -2, 0};
int dy[4] = {0, 2, 0, -2};
set<pair<int, int>> s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  int cnt = 0;
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    if (s.find({x, y}) != s.end()) cnt--;
    s.insert({x, y});
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
      if (s.find({nx, ny}) != s.end()) continue;
      cnt++;
      s.insert({nx, ny});
    }
  }

  cout << cnt;
  return 0;
}
