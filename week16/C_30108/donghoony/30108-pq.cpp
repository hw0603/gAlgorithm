#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int INF = 0x3f3f3f3f;

ll N, t, a[303030], ans;
vector<int> g[303030];
priority_queue<pair<int, int>> pq;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);\
    cin >> N;
    for (int i = 2; i <= N; i++) {
        cin >> t;
        g[t].push_back(i);
    }
    for (int i = 1; i <= N; i++) cin >> a[i];
    pq.emplace(a[1], 1);
    while (!pq.empty()) {
        auto [val, cur] = pq.top(); pq.pop();
        for (auto& nxt : g[cur]) pq.emplace(a[nxt], nxt);
        ans += val;
        cout << ans << '\n';
    }
    return 0;
}
