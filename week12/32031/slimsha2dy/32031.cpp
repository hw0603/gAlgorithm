#include <iostream>
#include <queue>

using namespace std;

int n, m;
char arr[202][202];
bool vis[404][404];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool func(int x, int y, int dir) {
  char c = arr[x/2][y/2];
  if (dir == 0 && (x%2 == 0 && (c == 'H' || c == 'O'))) return 1;
  if (dir == 1 && (y%2 == 0 && (c == 'I' || c == 'O'))) return 1;
  if (dir == 2 && (x%2 == 1 && (c == 'H' || c == 'O'))) return 1;
  if (dir == 3 && (y%2 == 1 && (c == 'I' || c == 'O'))) return 1;
  
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> arr[i][j];

  queue<pair<int ,int>> q;
  int cnt = 0;
  for (int i = 0; i < 2*n; ++i) {
    for (int j = 0; j < 2*m; ++j) {
      if (vis[i][j]) continue;
      cnt++;
      bool wiahrae = 1;
      vis[i][j] = 1;
      q.push({i, j});
      while (!q.empty()) {
        pair<int, int> tmp = q.front(); q.pop();
        if (arr[tmp.first/2][tmp.second/2] == 'O') wiahrae = 0;
        for (int dir = 0; dir < 4; ++dir) {
          if (func(tmp.first, tmp.second, dir)) continue;
          int nx = tmp.first + dx[dir];
          int ny = tmp.second + dy[dir];
          if (nx < 0 || nx >= 2*n || ny < 0 || ny >= 2*m) continue;
          if (vis[nx][ny]) continue;
          vis[nx][ny] = 1;
          q.push({nx, ny});
        }
      }
      if (wiahrae) cnt++;
    }
  }
  cout << cnt;
}
