#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set<string> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, p, w, l, g;
    cin >> n >> p >> w >> l >> g;

    string name;
    char wORl;
    for (int i = 0; i < p; i++) {
        cin >> name >> wORl;
        if (wORl == 'W') {
            s.insert(name);
        }
    }

    int score = 0;
    for (int i = 0; i < n; i++) {
        cin >> name;
        if (s.find(name) != s.end()) {
            score += w;
        }
        else {
            score = max(0, score - l);
        }
        cout << score << endl;

        if (score >= g) {
            cout << "I AM NOT IRONMAN!!";
            return 0;
        }
    }

    cout << "I AM IRONMAN!!";
    return 0;
}
