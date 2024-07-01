#include <iostream>
#include <queue>

using namespace std;

int n, m;
string board[1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  int bd = 0;
  pair<int, int> st;
  for (int i = 0; i < n; ++i) {
    cin >> board[i];
    for (int j = 0; j < m; ++j) {
      char c = board[i][j];
      if (c == '*' || c == '#') bd++;
      else if (c == '@') st = {i, j};
    }
  }
  queue<pair<int, int>> q;
  int boom = 0;
  for (int i = 0; i < 4; ++i) {
    int nx = st.first + dx[i];
    int ny = st.second + dy[i];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    if (board[nx][ny] == '|') continue;
    if (board[nx][ny] == '*') {
      q.push({nx, ny});
      board[nx][ny] = '.';
      boom++;
    }
    if (board[nx][ny] == '#') board[nx][ny] = '*';
    nx += dx[i]; ny += dy[i];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    if (board[nx][ny] == '|') continue;
    if (board[nx][ny] == '*') {
      q.push({nx, ny});
      board[nx][ny] = '.';
      boom++;
    }
    if (board[nx][ny] == '#') board[nx][ny] = '*';
  }
  while (!q.empty()) {
    pair<int, int> tmp = q.front(); q.pop();
    for (int i = 0; i < 4; ++i) {
      int nx = tmp.first + dx[i];
      int ny = tmp.second + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (board[nx][ny] == '|') continue;
      if (board[nx][ny] == '*') {
        q.push({nx, ny});
        board[nx][ny] = '.';
        boom++;
      }
      if (board[nx][ny] == '#') board[nx][ny] = '*';
    }
  }
  cout << boom << ' ' << bd-boom;
}
