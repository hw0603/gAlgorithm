#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long d;
int m[100002], w[100002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> d;
  int mi = 0;
  int wi = 0;
  for (int i = 0; i < n; ++i) {
    int a, x;
    cin >> a >> x;
    if (a == 1) m[mi++] = x;
    else w[wi++] = x;
  }

  sort(m, m+mi);
  sort(w, w+wi);

  int mt = 0;
  int wt = 0;
  int res = 0;
  while (mt < mi) {
    if (d <= m[mt]) {
      if (wt == wi) break;
      d *= w[wt++];
      res++;
    }
    else {
      d += m[mt++];
      res++;
    }
  }
  while (wt < wi) {
    d *= w[wt++];
    res++;
  }
  cout << res;
}
