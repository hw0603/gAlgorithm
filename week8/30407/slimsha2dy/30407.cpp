#include <iostream>

using namespace std;

int n, h, d, foot;
int arr[20];
int skill[20];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> h >> d >> foot;
  for (int i = 0; i < n; ++i) cin >> arr[i];

  int maxi = 0;
  for (int i = 0; i < (1<<n); ++i) {
    for (int j = 0; j < n+1; ++j) {
      int tmpd = d;
      int total = 0;
      for (int k = 0; k < n; ++k) {
        int dmg;
        if (k == j)
          dmg = max(0, arr[k] - tmpd);
        else if (i & (1<<k))
          dmg = max(0,(arr[k] - tmpd)) / 2;
        else {
          tmpd += foot;
          dmg = max(0, arr[k] - tmpd);
        }

        if (k == j+1) continue;
        total += dmg;
      }
      maxi = max(maxi, h - total);
    }
  }
  if (maxi == 0) cout << -1;
  else cout << maxi;
}
