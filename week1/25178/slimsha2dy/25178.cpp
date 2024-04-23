#include <iostream>
#include <vector>

using namespace std;

int n;
string vowel = "aeiou";
int cnt_a[5], cnt_b[5];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  string a, b;
  cin >> a;
  cin >> b;

  vector<char> c, d;
  if (a[0] != b[0] || a[n-1] != b[n-1]) {
    cout << "NO";
    return 0;
  }
  for (int i = 1; i < n; ++i) {
    bool flag = true;
    for (int j = 0; j < 5; ++j) {
      if (vowel[j] == a[i]) {
        cnt_a[j]++;
        flag = false;
        break;
      }
    }
    if (flag) {
      c.push_back(a[i]);
    }
  }
  for (int i = 1; i < n; ++i) {
    bool flag = true;
    for (int j = 0; j < 5; ++j) {
      if (vowel[j] == b[i]) {
        cnt_b[j]++;
        flag = false;
        break;
      }
    }
    if (flag) {
      d.push_back(b[i]);
    }
  }
  for (int i = 0; i < 5; ++i) {
    if (cnt_b[i] != cnt_a[i]) {
      cout << "NO";
      return 0;
    }
  }
  for (int i = 0; i < c.size(); ++i) {
    if (c[i] != d[i]) {
      cout << "NO";
      return 0;
    }
  } 
  cout << "YES";
}
