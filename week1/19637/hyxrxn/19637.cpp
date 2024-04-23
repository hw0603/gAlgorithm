#include <iostream>
#include <vector>
using namespace std;

vector<pair<string, int>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;

    cin >> n >> m;

    string name;
    int max;
    for (int i = 0; i < n; i++) {
        cin >> name >> max;
        v.push_back(make_pair(name, max));
    }

    int d;
    int l, u, mid, answer;
    for (int i = 0; i < m; i++) {
        cin >> d;
        l = 0;
        u = v.size() - 1;
        answer = l;
        while (l != u) {
            mid = (l + u) / 2;
            if (d <= v[mid].second) {
                u = mid;
                answer = u;
            }
            else {
                l = mid + 1;
                answer = l;
            }
        }
        cout << v[answer].first << "\n";
    }

    return 0;
}
