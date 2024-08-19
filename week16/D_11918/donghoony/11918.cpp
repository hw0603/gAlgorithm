#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;

ll N, L, ans;
pair<ll, ll> arr[151515];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        ll t; cin >> t;
        arr[i] = {t - L, t + L};
    }
    sort(arr, arr+N);
    ll bf = -LINF;
    for (int i = 0; i < N-1; i++) {
        ans += max(0LL, arr[i].second - max(arr[i+1].first, bf));
        bf = arr[i].second;
    }
    cout << ans << '\n';

    return 0;
}
