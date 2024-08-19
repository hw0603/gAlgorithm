#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int INF = 0x3f3f3f3f;

ll N, L, a[202020], on[202020], off[202020], d[202020], ans, t;

ll f(int x) {
    if (x > N) return 0;
    ll& ret = d[x];
    if (ret != -1) return ret;
    ret = off[x] - off[x-1];
    ret += max(f(x+1), on[N] - on[x]);
    return ret;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    memset(d, -1, sizeof d);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) {
        cin >> t;
        off[i] += off[i-1], on[i] += on[i-1];
        if (t == 0) off[i] += a[i];
        else on[i] += a[i];
    }

    for (int i = 1; i <= N; i++) ans = max(ans, on[i-1] + f(i));
    cout << ans << '\n';
    return 0;
}
