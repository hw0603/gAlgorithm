#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a, b, c, k;
vector<pair<int, int>> v; // first는 횟수, second는 쓰이는 에너지
int dp[1000001]; // 에너지가 i일 때의 최소횟수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b >> c >> k;
    v.push_back({2, c + c});
    v.push_back({2, a + b});
    v.push_back({3, a + a + c});
    v.push_back({3, b + b + c});
    v.push_back({4, a + a + a + a});
    v.push_back({4, b + b + b + b});

    for (int i = 1; i < 1000001; i++) {
        dp[i] = 10000000;
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i].second <= k) {
            dp[v[i].second] = min(dp[v[i].second], v[i].first);
//            cout << "dp[" << v[i].second << "] = " << dp[v[i].second] << endl;
        }
    }

    for (int i = 1; i < k; i++) {
        for (int j = 0; j < v.size(); j++) {
            if (i + v[j].second <= k) {
                dp[i + v[j].second] = min(dp[i + v[j].second], dp[i] + v[j].first);
//                cout << "dp[" << i + v[j].second << "] = " << dp[i + v[j].second] << endl;
            }
        }
    }

    if (dp[k] == 10000000) {
        cout << -1;
        return 0;
    }
    cout << dp[k];
    return 0;
}
