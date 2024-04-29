#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int now;
    cin >> now;
    int min = now;
    int max = 0;
    cout << 0 << " ";
    for (int i = 1; i < n; i++) {
        cin >> now;
        max = std::max(max, now - min);
        min = std::min(min, now);
        cout << max << " ";
    }

    return 0;
}
