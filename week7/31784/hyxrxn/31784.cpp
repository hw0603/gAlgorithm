#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    string s;

    cin >> n >> k >> s;

    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == 'A') {
            continue;
        }
        if ('Z' + 1 - s[i] <= k) {
            k -= 'Z' + 1 - s[i];
            s[i] = 'A';
        }
        if (k == 0) {
            cout << s;
            return 0;
        }
    }

    k = (k + s[s.length() - 1] - 'A') % 26; // 0이 A
    s[s.length() - 1] = 'A' + k;

    cout << s;

    return 0;
}

// 78%
