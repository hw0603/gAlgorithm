#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, K, cnt, ans, v[10001], t, f = 1;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> K;
    while (N--) {
        cin >> t;
        if (f ^ v[t]) v[t] = f, cnt++;
        if (cnt == K) ans++, cnt = 0, f = !f;
    }
    cout << ans + 1 << '\n';
    return 0;
}
