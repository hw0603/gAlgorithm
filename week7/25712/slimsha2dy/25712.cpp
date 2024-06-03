#include <iostream>
#include <vector>

using namespace std;

int n, m;
int num[100002];
vector<pair<int, int>> arr[100002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= m; ++i) cin >> num[i];
  arr[0].push_back({1, n});
  for (int i = 1; i <= m; ++i) {
    for (int j = 0; j*2 < num[i]; ++j) {
      int st, en;
      cin >> st >> en;
      for (pair<int, int> prev : arr[i-1]) {
        if (prev.first <= en && prev.second >= st) {
          arr[i].push_back({st, en});
          break;
        }
      }
    }
  }
  if (arr[m].size() == 0) cout << "NO";
  else cout << "YES";
}
