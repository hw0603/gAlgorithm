#include <iostream>
#include <tuple>
#include <queue>
#include <cstdlib>
using namespace std;

int n;
int arr[1001][1001];
int visit[1001][1001] = {0};
int mini[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
priority_queue<tuple<int, int, int>> pq;
int x, y, nx, ny;

void di() {
    visit[0][0] = 1;
    pq.push({0, 0, 0});
    mini[0][0] = 0;

    while (!pq.empty()) {
        tuple<int, int, int> t = pq.top();
        x = get<1>(t);
        y = get<2>(t);
        pq.pop();
        visit[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < n && visit[nx][ny] == 0) {
                int nowM = max(mini[x][y], abs(arr[nx][ny] - arr[x][y]));
                if (nowM < mini[nx][ny]) {
                    mini[nx][ny] = nowM;
                    pq.push({-mini[nx][ny], nx, ny});
                }
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            mini[i][j] = 2000000000;
        }
    }

    di();

    cout << mini[n - 1][n - 1];
    return 0;
}