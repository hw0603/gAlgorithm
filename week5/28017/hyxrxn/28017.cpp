#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[501][501];
int answer[501][501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j]; // i번째 판의 j번째 무기의 클리어 시간
        }
    }

    for (int j = 0; j < m; j++) {
        answer[0][j] = arr[0][j];
    }

    for (int i = 1; i < n; i++) {
        vector<pair<int, int>> v;
        for (int j = 0; j < m; j++) {
            v.push_back({answer[i - 1][j], j});
        }
        sort(v.begin(), v.end());
        for (int j = 0; j < m; j++) {
            if (v[0].second != j) {
                answer[i][j] = v[0].first + arr[i][j];
            } else {
                answer[i][j] = v[1].first + arr[i][j];
            }
        }
    }

    vector<int> v;
    for (int j = 0; j < m; j++) {
        v.push_back(answer[n - 1][j]);
    }
    sort(v.begin(), v.end());

    cout << v[0];

    return 0;
}