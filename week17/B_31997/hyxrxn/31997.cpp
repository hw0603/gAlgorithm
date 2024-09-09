#include <iostream>
#include <algorithm>
using namespace std;

int n, m, t;
int arrive[202020];
int leave[202020];
long long st[202020];
long long et[202020];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        cin >> arrive[i] >> leave[i];
    }

    int c, d, s, e;
    for (int i = 0; i < m; i++) {
        cin >> c >> d;
        s = max(arrive[c], arrive[d]);
        e = min(leave[c], leave[d]);
        if (s < e) {
            st[s]++;
            et[e]++;
        }
    }

    cout << st[0] - et[0] << "\n";
    for (int i = 1; i < t; i++) {
        st[i] += st[i - 1];
        et[i] += et[i - 1];
        cout << st[i] - et[i] << "\n";
    }

    return 0;
}