#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int INF = 0x3f3f3f3f;
constexpr ll MOD = 1e9;

ll N, K, ans, p_cnt;
string s;
vector<int> c, p;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> K >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'C') c.push_back(i);
        else p.push_back(i);
    }
    for (int i = 0, j = p.size() - 1; i < min({c.size(), p.size(), (size_t) K}) && c[i] < p[j]; i++, j--) 
      swap(s[c[i]], s[p[j]]);
    for (auto ch : s) {
        if (ch == 'P') { p_cnt++; continue; }
        ans += p_cnt * (p_cnt - 1) / 2;
    }
    cout << ans << '\n';
    return 0;
}
