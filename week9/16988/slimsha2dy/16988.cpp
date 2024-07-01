#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int board[23][23];
bool vis[23][23];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int func(pair<int, int> a, pair<int, int> b) {
  int res = 0;

  board[a.first][a.second] = 1;
  board[b.first][b.second] = 1;

  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < 4; ++i) {
    queue<pair<int, int>> q;
    int na = a.first + dx[i];
    int nb = a.second + dy[i];
    if (na < 0 || na >= n || nb < 0 || nb >= m) continue;
    if (vis[na][nb] || board[na][nb] != 2) continue;
    q.push({na, nb});
    vis[na][nb] = 1;
    int flag = 0;
    int cnt = 1;
    while (!q.empty()) {
      pair<int, int> tmp = q.front(); q.pop();
      for (int dir = 0; dir < 4; ++dir) {
        int nx = tmp.first + dx[dir];
        int ny = tmp.second + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (board[nx][ny] == 0) {
          flag = 1;
          continue;
        }
        if (vis[nx][ny] || board[nx][ny] == 1) continue;
        q.push({nx, ny});
        cnt++;
        vis[nx][ny] = 1;
      }
    }
    if (!flag) {
      res += cnt;
    }
  }
  for (int i = 0; i < 4; ++i) {
    queue<pair<int, int>> q;
    int na = b.first + dx[i];
    int nb = b.second + dy[i];
    if (na < 0 || na >= n || nb < 0 || nb >= m) continue;
    if (vis[na][nb] || board[na][nb] != 2) continue;
    q.push({na, nb});
    vis[na][nb] = 1;
    int flag = 0;
    int cnt = 1;
    while (!q.empty()) {
      pair<int, int> tmp = q.front(); q.pop();
      for (int dir = 0; dir < 4; ++dir) {
        int nx = tmp.first + dx[dir];
        int ny = tmp.second + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (board[nx][ny] == 0) {
          flag = 1;
          continue;
        }
        if (vis[nx][ny] || board[nx][ny] == 1) continue;
        q.push({nx, ny});
        cnt++;
        vis[nx][ny] = 1;
      }
    }
    if (!flag) {
      res += cnt;
    }
  }
  board[a.first][a.second] = 0;
  board[b.first][b.second] = 0;
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> board[i][j];

  int maxi = 0;
  for (int i = 0; i < n*m-1; ++i) {
    if (board[i/m][i%m]) continue;
    for (int j = i+1; j < n*m; ++j) {
      if (board[j/m][j%m]) continue;
      maxi = max(maxi, func({i/m, i%m}, {j/m, j%m}));
    }
  }
  cout << maxi;
}
