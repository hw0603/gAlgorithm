#include <iostream>
#include <queue>

using namespace std;

int n, m;
char a[52][52], b[52][52];
bool vis[52][52];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> a[i][j];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> b[i][j];

  queue<pair<int, int>> q;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (vis[i][j]) continue;
      q.push({i, j});
      char c = b[i][j];
      while (!q.empty()) {
        pair<int, int> tmp = q.front(); q.pop();
        if (b[tmp.first][tmp.second] != c) {
          cout << "NO";
          return 0;
        }
        for (int i = 0; i < 4; ++i) {
          int nx = tmp.first + dx[i];
          int ny = tmp.second + dy[i];
          if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if (vis[nx][ny] || a[nx][ny] != a[tmp.first][tmp.second]) continue;
          vis[nx][ny] = 1;
          q.push({nx, ny});
        }
      }
    }
  }
  cout << "YES";
}
