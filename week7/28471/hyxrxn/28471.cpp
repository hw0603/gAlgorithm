#include <iostream>
#include <queue>

using namespace std;

int n;
char arr[2001][2001];
int visit[2001][2001] = {0};

int dx[7] = {-1, 1, 1, 0, 0, -1, -1};
int dy[7] = {0, 1, -1, 1, -1, 1, -1};
int nx, ny;

queue<pair<int, int>> q;
int answer = 0;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 'F') {
                q.push({i, j});
                visit[i][j] = 1;
                while (!q.empty()) {
                    pair<int, int> p = q.front();
                    q.pop();
                    for (int k = 0; k < 7; k++) {
                        nx = p.first + dx[k];
                        ny = p.second + dy[k];
                        if (0 <= nx && nx < n && 0 <= ny && ny < n && visit[nx][ny] == 0) {
                            if (arr[nx][ny] == '.') {
                                answer++;
                                q.push({nx, ny});
                                visit[nx][ny] = 1;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << answer;

    return 0;
}