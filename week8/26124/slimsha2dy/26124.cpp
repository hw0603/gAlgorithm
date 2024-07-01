#include <iostream>

using namespace std;

int n, m;
int board[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> board[i][j];

  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (board[i][j] == -1 || board[i][j] == 0) continue;
      int flag = 0;
      for (int dir = 0; dir < 4; ++dir) {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (board[nx][ny] == -1) continue;
        int from = board[i][j];
        int to = board[nx][ny];
        if (abs(from - to) > 1) {
          cout << -1;
          return 0;
        }
        if (from < to) flag = 1;
      }
      if (!flag) res++;
    }
  }
  cout << res;
}
