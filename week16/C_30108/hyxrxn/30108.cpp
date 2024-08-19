#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> arr[300001];
int num[300001];
priority_queue<pair<int, int>> pq;
long long answer = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    int dummy;
    for (int i = 2; i <= n; i++) {
        cin >> dummy;
        arr[dummy].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }

    pq.push({num[1], 0});
    for (int i = 0; i < arr[1].size(); i++) {
        pq.push({num[arr[1][i]], arr[1][i]});
    }

    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        int jungjum = p.second;
        int jungsu = p.first;
        pq.pop();
        answer += (long long)jungsu;
        cout << answer << "\n";
        for (int i = 0; i < arr[jungjum].size(); i++) {
            pq.push({num[arr[jungjum][i]], arr[jungjum][i]});
        }
    }

    return 0;
}