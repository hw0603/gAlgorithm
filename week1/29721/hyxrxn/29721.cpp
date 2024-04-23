#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    set<pair<int, int>> v;
    int a, b;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        v.insert(make_pair(a, b));
    }

    int dx[4] = {2, -2, 0, 0};
    int dy[4] = {0, 0, 2, -2};

    int x, y;
    set<pair<int, int>> s;
    for (const auto &item: v) {
        for (int i = 0; i < 4; i++) {
            x = item.first + dx[i];
            y = item.second + dy[i];
            if (x > 0 && x <= n && y > 0 && y <= n && v.find(make_pair(x, y)) == v.end()) {
                s.insert(make_pair(x, y));
            }
        }
    }

    cout << s.size();

    return 0;
}
