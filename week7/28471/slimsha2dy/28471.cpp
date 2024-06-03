#include <iostream>
#include <queue>

using namespace std;

int n;
string board[2002];
bool vis[2002][2002];
int dx[7] = {1, 1, 0, 0, -1, -1, -1};
int dy[7] = {1, -1, 1, -1, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> board[i];

  queue<pair<int, int>> q;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (board[i][j] == 'F') {
        q.push({i, j});
        vis[i][j] = 1;
      }

  int res = 0;
  while (!q.empty()) {
    pair<int, int> tmp = q.front(); q.pop();
    for (int i = 0; i < 7; ++i) {
      int nx = tmp.first + dx[i];
      int ny = tmp.second + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if (vis[nx][ny] == 1 || board[nx][ny] == '#') continue;
      vis[nx][ny] = 1;
      res++;
      q.push({nx, ny});
    }
  }
  cout << res;
}
