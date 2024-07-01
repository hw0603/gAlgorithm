#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int arr[21][21];
vector<pair<int, int>> blank;
int maxi = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int nx, ny;

int bfs(int i, int j, int visit[21][21]) {
    bool isZero = false;
    int cur = 0;
    queue<pair<int, int>> q;
    q.push({i, j});
    visit[i][j] = 1;
    cur++;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            nx = p.first + dx[k];
            ny = p.second + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && visit[nx][ny] == 0) {
                if (arr[nx][ny] == 0) {
                    isZero = true;
                }
                if (arr[nx][ny] == 2) {
                    q.push({nx, ny});
                    visit[nx][ny] = 1;
                    cur++;
                }
            }
        }
    }
    if (isZero) {
        return 0;
    }
    return cur;
}

void cal() {
    int count = 0;
    int visit[21][21] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 2 && visit[i][j] == 0) {
                count += bfs(i, j, visit);
            }
        }
    }
    maxi = max(maxi, count);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                blank.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < blank.size() - 1; i++) {
        arr[blank[i].first][blank[i].second] = 1;
        for (int j = i + 1; j < blank.size(); j++) {
            arr[blank[j].first][blank[j].second] = 1;
            cal();
            arr[blank[j].first][blank[j].second] = 0;
        }
        arr[blank[i].first][blank[i].second] = 0;
    }

    cout << maxi;
    return 0;
}
