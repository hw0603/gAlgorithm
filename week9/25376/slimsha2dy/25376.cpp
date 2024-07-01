#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> se[22];
bool vis[2000000];
int dp[2000000];

void func(int tmp) {
  if (vis[tmp]) {
    return;
  }
  vis[tmp] = 1;
  for (int i = 1; i <= n; ++i) {
    if (tmp & 1<<(n-i)) continue;
    int nxt = tmp ^ 1<<(n-i);
    for (int j : se[i]) {
      nxt ^= 1<<(n-j);
    }
    func(nxt);
    dp[tmp] = min(dp[nxt]+1, dp[tmp]);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  int st = 0;
  for (int i = 0; i < n; ++i) {
    int input;
    cin >> input;
    st = st<<1;
    st += input;
  }
  for (int i = 1; i <= n; ++i) {
    int cnt;
    cin >> cnt;
    while (cnt--) {
      int tmp;
      cin >> tmp;
      se[i].push_back(tmp);
    }
  }
  fill(dp, dp+2000000, 2100000000);
  dp[(1<<n)-1] = 0;
  vis[(1<<n)-1] = 1;

  func(st);
  fill(vis, vis+2000000, 0);
  vis[(1 << n) - 1] = 1;
  func(st);
  fill(vis, vis+2000000, 0);
  vis[(1 << n) - 1] = 1;
  func(st);

  if (dp[st] == 2100000000) cout << -1;
  else cout << dp[st];
}

// 켜져 있는 건 직접 못 끈다는 것을 나중에 발견
// 처음에는 dep를 인자로 받고 다 1이면 dep을 최소에 저장하는 식으로 했음 -> vis[tmp] 방문 시 스킵하도록 했는데 그러면 이후에 나올 수 있는 더 좋은 상황을 지나쳐서 틀림
// 그래서 한 번 다 돌고 나면 vis[tmp]를 0으로 바꾸도록 했으나 시간초과가 남
// dep을 인자로 받지 말고 현재 상태에서 끝에 도달할 수 있는 가장 짧은 시간을 리턴하도록 하고 캐시에 저장 -> vis[tmp]면 캐시를 리턴하도록 -> 이거 왜 틀림?
