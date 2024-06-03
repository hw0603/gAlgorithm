#include <iostream>
#include <vector>
using namespace std;

int n, m;
int length[100001];

vector<pair<int, int>> v[100001];
int s, e;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> length[i];
    }
    for (int i = 0; i < length[1] / 2; i++) {
        cin >> s >> e;
        v[1].push_back({s, e});
    }
    for (int i = 2; i <= m; i++) {
        for (int j = 0; j < length[i] / 2; j++) {
            cin >> s >> e;
            for (int k = 0; k < v[i - 1].size(); k++) {
                if (!(v[i - 1][k].first > e || v[i - 1][k].second < s)) {
                    v[i].push_back({s, e});
                }
            }
        }
        if (v[i].empty()) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}
