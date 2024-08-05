#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int INF = 0x3f3f3f3f;
constexpr ll MOD = 1e9;

string s;
deque<char> dq;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> s;
    dq.push_back(s[0]);
    for (int i = 1; i < s.length(); i++) {
        if (dq.front() >= s[i]) dq.push_front(s[i]);
        else dq.push_back(s[i]);
    }
    for (auto& c : dq) cout << c << "";
    cout << '\n';
    return 0;
}
