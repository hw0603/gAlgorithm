#include <iostream>
#include <algorithm>

using namespace std;

int r, c, n;
int arr3[1000002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> r >> c;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int input;
    cin >> input;
    arr3[input]++;
  }
  int cnt = 0;
  for (int i = 0; i < 1000001; ++i) cnt += min(c, arr3[i]);
  cout << min(r*c, cnt);
}
