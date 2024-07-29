#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int n, q, k;
int command[101010], arg[101010];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> q >> k;

  bool reversed = 0;
  deque<int> dq;
  int last = -1;
  int zerocnt = 0;
  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a;
    command[i] = a;
    if (!a) {
      cin >> b;
      arg[i] = b;
      zerocnt++;
    }
    if (a == 1) last = i;
  }
  for (int i = 0; i < last; ++i) {
    if (command[i] == 0) dq.push_back(arg[i]);
    if (command[i] == 2) reversed = !reversed;
  }
  if (last > 0) {
    if (reversed) sort(dq.begin(), dq.end(), greater<int>());
    else sort(dq.begin(), dq.end());
  }
  for (int i = last+1; i < q; ++i) {
    int a = command[i];
    if (!a) {
      int b = arg[i];
      if (reversed) dq.push_back(b);
      else dq.push_front(b);
    }
    else if (a == 2) {
      reversed = !reversed;
    }
  }
  if (reversed) cout << dq[zerocnt-k];
  else cout << dq[k-1];
}
