#include <iostream>
#include <queue>

using namespace std;

int n, m;
int board[55][55];
int vis[55][55];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> board[i][j];

  queue<pair<int, int>> q;
  int maxi = 0;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (board[i][j] == 0) continue;
      memset(vis, 0, sizeof(vis));
      vis[i][j] = 1;
      q.push({i, j});
      while (!q.empty()) {
        pair<int, int> tmp = q.front(); q.pop();
        for (int dir = 0; dir < 4; ++dir) {
          int nx = tmp.first + dx[dir];
          int ny = tmp.second + dy[dir];
          if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if (vis[nx][ny] || board[nx][ny] == 0) continue;
          vis[nx][ny] = vis[tmp.first][tmp.second] + 1;
          if (vis[nx][ny] == maxi) {
            res = max(res, board[i][j] + board[nx][ny]);
          }
          if (vis[nx][ny] > maxi) {
            res = board[i][j] + board[nx][ny];
            maxi = vis[nx][ny];
          }
          q.push({nx, ny});
        }
      }
    }
  }
  cout << res;
}
