#include <iostream>
#include <vector>

using namespace std;

int n;
char board[10][10];
bool jang[10][10];
vector<pair<int, int>> tc;
bool comb[40];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      cin >> board[i][j];
      if (board[i][j] == 'T') tc.push_back({i, j});
    }
  for (int i = 0; i < 3; ++i) comb[n*n - i - 1] = 1;

  do {
    for (int i = 0; i < 10; ++i) fill(jang[i], jang[i]+10, 0);
    bool flag= 0;
    for (int i = 0; i < n; ++i) 
      for (int j = 0; j < n; ++j)
        if (comb[i*n + j]) {
          if (board[i][j] == 'S' || board[i][j] == 'T') flag = 1;
          jang[i][j] = 1;
        }
    if (flag) continue;
    for (pair<int, int> p : tc) {
      for (int dir = 0; dir < 4 && !flag; ++dir) {
        pair<int, int> tmp = p;
        while (tmp.first >= 0 && tmp.first < n && tmp.second >= 0 && tmp.second < n &&!jang[tmp.first][tmp.second]) {
          if (board[tmp.first][tmp.second] == 'S') {
            flag = 1;
            break;
          }
          tmp.first += dx[dir];
          tmp.second += dy[dir];
        }
      }
    }
    if (!flag) {
      cout << "YES";
      return 0;
    }
  } while (next_permutation(comb, comb + n*n));

  cout << "NO";
}
