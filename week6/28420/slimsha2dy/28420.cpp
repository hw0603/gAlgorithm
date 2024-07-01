#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a, b, c;
int board[303][303];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  cin >> a >> b >> c;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      int input;
      cin >> input;
      board[i][j] = board[i][j-1] + input;
    }

  int mini = 2147483647;
  for (int i = 1; i <= n-a+1; ++i) {
    for (int j = 1; j <= m-(b+c)+1; ++j) {
      int tmp = 0;
      for (int x = i; x <= i+a-1; ++x) {
        tmp += board[x][j+b+c-1] - board[x][j-1];
      }
      mini = min(mini, tmp);
    }
  }
  for (int i = 1; i <= n-(a+b)+1; ++i) {
    for (int j = 1; j <= m-(a+c)+1; ++j) {
      int tmp = 0;
      for (int x = i; x <= i+a-1; ++x) {
        tmp += board[x][j+c-1] - board[x][j-1];
      }
      for (int x = i+a; x <= i+a+b-1; ++x) {
        tmp += board[x][j+c+a-1] - board[x][j+c-1];
      }
      mini = min(mini, tmp);
    }
  }
  for (int i = 1; i <= n-(a+c)+1; ++i) {
    for (int j = 1; j <= m-(a+b)+1; ++j) {
      int tmp = 0;
      for (int x = i; x <= i+a-1; ++x) {
        tmp += board[x][j+b-1] - board[x][j-1];
      }
      for (int x = i+a; x <= i+a+c-1; ++x) {
        tmp += board[x][j+b+a-1] - board[x][j+b-1];
      }
      mini = min(mini, tmp);
    }
  }
  cout << mini;
}
