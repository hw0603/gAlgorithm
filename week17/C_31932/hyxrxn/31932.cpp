#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;

// 도착지점을 갈 수 있는 빙하 탐색하며 그 빙하에 도달할 수 있는 최댓값 갱신
// 반복하며 시작 지점의 도달 최댓값 갱신
// 도달 최댓값이 먹을 수 있는 연어의 최대 수일듯...

int n, m;
vector<vector<tuple<int, int, int>>> vec(101010);
priority_queue<pair<int, int>> pq;
int visit[101010] = {0};
int until[101010] = {0};

int main() {
    cin >> n >> m;

    int u, v, d, t;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> d >> t;
        vec[u].push_back({v, d, t});
        vec[v].push_back({u, d, t});
    }

    until[1] = -1;
    visit[n] = 1;
    for (const auto &item: vec[n]) {
        int next = get<0>(item);
        int dis = get<1>(item);
        int tim = get<2>(item);

        if (tim - dis >= 0) {
            until[next] = max(until[next], tim - dis);
            pq.push({until[next], next});
        }
    }

    while (!pq.empty()) {
        pair<int, int> a = pq.top();
        pq.pop();
        int pre = a.second;
        int now = a.first;
        visit[pre] = 1;

        for (const auto &item: vec[pre]) {
            int next = get<0>(item);
            int dis = get<1>(item);
            int tim = get<2>(item);

            if (visit[next] == 0 && now <= tim) {
                until[next] = max(until[next], now - dis);
                pq.push({until[next], next});
            }
        }
    }

    cout << until[1];

    return 0;
}

// 18에서 런타임에러