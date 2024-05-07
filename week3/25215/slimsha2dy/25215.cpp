#include <iostream>

using namespace std;

string s;
bool arr[3004];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> s;
  int n = s.size();

  for (int i = 0; i < n; ++i) {
    if (s[i] >= 'a' && s[i] <= 'z') arr[i+1] = 0;
    else arr[i+1] = 1;
  }
  arr[n+1] = arr[n];

  int cnt = n;
  for (int i = 1; i <= n; ++i) {
    if (arr[i-1] != arr[i]) {
      cnt++;
      if (arr[i] != arr[i+1]) i++;
    }
  }
  cout << cnt;
}
