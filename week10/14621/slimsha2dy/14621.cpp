#include <iostream>
#include <vector>

using namespace std;

int n, m;
char se[1005];
int d[1005];
vector<pair<int, int>> adj[10005];
int inf = 2147483647;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> se[i];

  fill(d, d+n+1, inf);
  for (int i = 0; i < m; ++i) {
    int u, v, d;
    cin >> u >> v >> d;
    adj[u].push_back({v, d});
  }
}
