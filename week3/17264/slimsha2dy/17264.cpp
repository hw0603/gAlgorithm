#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, p;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> p;
  int w, l, g;
  cin >> w >> l >> g;

  vector<string> bus;
  for (int i = 0; i < p; ++i) {
    string input;
    char wl;
    cin >> input >> wl;
    if (wl == 'W') bus.push_back(input);
  }

  int tmp = 0;
  for (int i = 0; i < n; ++i) {
    string input;
    cin >> input;
    if (count(bus.begin(), bus.end(), input) == 0) tmp = max(tmp-l, 0);
    else tmp += w;
    if (tmp >= g) {
      cout << "I AM NOT IRONMAN!!";
      return 0;
    }
  }
  cout << "I AM IRONMAN!!";
}
