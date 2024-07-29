#include <iostream>

using namespace std;

int n, m, v;
int arr[202020];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> v;
  for (int i = 0; i < n; ++i) cin >> arr[i];

  while (m--) {
    int input;
    cin >> input;
    if (input < v-1) {
      cout << arr[input] << '\n';
      continue;
    }
    cout << arr[(input-v+1) % (n-v+1) + v-1] << '\n';
  }
}
