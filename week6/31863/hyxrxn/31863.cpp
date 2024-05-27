#include <iostream>
#include <queue>
using namespace std;

int n, m;
char arr[1001][1001];
queue<pair<int, int>> q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int answer = 0;
int total = 0;

void bonjin(int x, int y) {
    arr[x][y] = '.';
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 2; j++) {
            int nx = x + j * dx[i];
            int ny = y + j * dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (arr[nx][ny] == '|') {
                    break;
                } else if (arr[nx][ny] == '*') {
                    q.push({nx, ny});
                    arr[nx][ny] = '.';
                    answer++;
                } else if (arr[nx][ny] == '#') {
                    arr[nx][ny] = '*';
                }
            }
        }
    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cout << arr[i][j];
//        }
//        cout << endl;
//    }
//    cout << endl;
}

void yeojin(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m) {
            if (arr[nx][ny] == '*') {
                q.push({nx, ny});
                arr[nx][ny] = '.';
                answer++;
            } else if (arr[nx][ny] == '#') {
                arr[nx][ny] = '*';
            }
        }
    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cout << arr[i][j];
//        }
//        cout << endl;
//    }
//    cout << endl;
}

int main() {
    cin >> n >> m;

    int startx, starty;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '@') {
                startx = i;
                starty = j;
            } else if (arr[i][j] == '*' || arr[i][j] == '#') {
                total++;
            }
        }
    }

    bonjin(startx, starty);
    while (!q.empty()) {
        pair<int, int> &pair = q.front();
        q.pop();
        yeojin(pair.first, pair.second);
    }

    cout << answer << " " << total - answer;

    return 0;
}