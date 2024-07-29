#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int INF = 0x3f3f3f3f;
constexpr ll MOD = 1e9;

ll N, M, V, t, arr[202020];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> M >> V;
    for (int i = 0; i < N; i++) cin >> arr[i];
    while (M--) {
        cin >> t;
        if (t < V) cout << arr[t] << '\n';
        else cout << arr[V + (t - V + 1) % (N - V + 1) - 1] << '\n';
    }
    return 0;
}
