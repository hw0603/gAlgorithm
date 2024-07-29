#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int INF = 0x3f3f3f3f;
constexpr ll MOD = 1e9;

ll T, N, m[101010][2], d[101010][2];
char c[101010][2];
string s;

map<char, function<ll(ll, ll)>> cal = {
        {'+', [](ll o, ll val){return o <= 0 ? 0 : o + val;}},
        {'-', [](ll o, ll val){return o <= 0 ? 0 : o - val;}},
        {'*', [](ll o, ll val){return o <= 0 ? 0 : o * val;}},
        {'/', [](ll o, ll val){return o <= 0 ? 0 : o / val;}}
};


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int p = 0; p < 2; p++) {
            cin >> s;
            c[i][p] = s[0], m[i][p] = s[1] - '0';
        }
    }
    d[0][1] = 1;
    for (int i = 1; i <= N; i++) {
        d[i][1] = max(d[i][1], cal[c[i][0]](d[i-1][1], m[i][0]));
        d[i][1] = max(d[i][1], cal[c[i][1]](d[i-1][1], m[i][1]));
        d[i][0] = max(d[i][0], cal[c[i][0]](d[i-1][0], m[i][0]));
        d[i][0] = max(d[i][0], cal[c[i][1]](d[i-1][0], m[i][1]));
        d[i][0] = max(d[i][0], d[i-1][1]);
    }
    if (d[N][0] <= 0 and d[N][1] <= 0) cout << "ddong game\n";
    else cout << max(d[N][0], d[N][1]) << '\n';
    return 0;
}
