#include <iostream>

using namespace std;

int n, k;
tuple<int, int, int> arr[22];
bool board[7][12];
int cnt;
int tmp;
int idx;

void func(int dep) {
  if (dep == idx) return;
  func(dep+1);
  int w, st, en;
  tie(w, st, en) = arr[dep];
  for (int i = st; i <= en; ++i)
    if (board[w][i]) return;

  for (int i = st; i <= en; ++i) board[w][i] = 1;
  tmp += en - st + 1;
  if (tmp < k) func(dep+1);
  else if (tmp == k) {
    cnt++;
  }
  for (int i = st; i <= en; ++i) board[w][i] = 0;
  tmp -= en - st + 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 5) continue;
    arr[idx++] = {a, b, c};
  }
  func(0);
  cout << cnt;
}
