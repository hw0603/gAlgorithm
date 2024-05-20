#include <iostream>

using namespace std;

int n, m, r;
int board[102][102];
bool fall[102][102];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int direction(char c) {
  if (c == 'E') return 0;
  if (c == 'W') return 1;
  if (c == 'S') return 2;
  return 3;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> r;
  for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> board[i][j];
  int res = 0;
  for (int i = 0; i < r*2; ++i) {
    if (i%2 == 0) {
      int x, y; char c;
      cin >> x >> y >> c;
      if (fall[x][y]) continue;
      int dir = direction(c);
      int tmp = board[x][y];
      fall[x][y] = 1;
      res++;
      while (1) {
        x += dx[dir];
        y += dy[dir];
        tmp--;
        if (x == 0 || x > n || y == 0 || y > m) break;
        if (tmp == 0) break;
        if (!fall[x][y]) {
          tmp = max(board[x][y], tmp);
          res++;
        }
        fall[x][y] = 1;
      }
    }
    else {
      int x, y;
      cin >> x >> y;
      fall[x][y] = 0;
    }
  }
  cout << res << '\n';
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (fall[i][j]) cout << "F ";
      else cout << "S ";
    }
    cout << '\n';
  }
}
