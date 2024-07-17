#include <iostream>
#include <queue>

using namespace std;

int n;
int board[1010][1010];
int d[1010][1010];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int INF = 2147483647;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> board[i][j];

  for (int i = 0; i < n; ++i) fill(d[i], d[i]+n, INF);
  d[0][0] = 0;

  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
  pq.push({d[0][0], 0, 0});
  while (!pq.empty()) {
    tuple<int, int, int> t = pq.top(); pq.pop();
    int tmp, x, y;
    tie(tmp, x, y) = t;
    if (d[x][y] != tmp) continue;
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      int dist = abs(board[nx][ny] - board[x][y]);
      if (d[nx][ny] <= max(tmp, dist)) continue;
      d[nx][ny] = max(tmp, dist);
      pq.push({d[nx][ny], nx, ny});
    }
  }

  cout << d[n-1][n-1];
}
