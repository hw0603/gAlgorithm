#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int INF = 0x3f3f3f3f;

ll N, t, a[303030], ans;
string s;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N; cin.ignore();
    getline(cin, s);
    for (int i = 0; i < N; i++) cin >> a[i];
    sort(a, a+N, greater<>());
    for (int i = 0; i < N; i++) ans += a[i], cout << ans << '\n';
    return 0;
}
