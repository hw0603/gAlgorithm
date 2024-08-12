#include <iostream>

using namespace std;

int n, k, q, m;
bool sleep[5050], chul[5050];
int acm[5050];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k >> q >> m;

  while (k--) {
    int input;
    cin >> input;
    sleep[input] = 1;;
  }
  while (q--) {
    int input;
    cin >> input;
    if (chul[input] || sleep[input]) continue;
    int tmp = input;
    while (tmp <= n+2) {
      if (!sleep[tmp]) chul[tmp] = 1;
      tmp += input;
    }
  }

  for (int i = 3; i <= n+2; ++i) {
    acm[i] = acm[i-1] + !chul[i];
  }

  while (m--) {
    int a, b;
    cin >> a >> b;
    cout << acm[b] - acm[a-1] << '\n';
  }
}
