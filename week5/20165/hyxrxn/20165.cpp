#include <iostream>
#include <queue>
using namespace std;

int n, m, r;

int arr[101][101];
int fall[101][101] = {0};

queue<pair<int, int>> q;
pair<int, int> p;

int answer = 0;

// 아래 -> x증가 오른쪽 -> y증가

void attack(int x, int y, char d) {
    q.push({x, y});
    while (!q.empty()) {
        p = q.front();
        q.pop();
        if (!fall[p.first][p.second]) {
            if (d == 'E') { // 오른쪽으로
                for (int i = 0; i < arr[p.first][p.second] && p.second + i <= m ; i++) {
                    q.push({p.first, p.second + i});
                }
            }
            if (d == 'W') { // 왼쪽으로
                for (int i = 0; i < arr[p.first][p.second] && p.second - i >= 1 ; i++) {
                    q.push({p.first, p.second - i});
                }
            }
            if (d == 'S') { // 아래로
                for (int i = 0; i < arr[p.first][p.second] && p.first + i <= n ; i++) {
                    q.push({p.first + i, p.second});
                }
            }
            if (d == 'N') { // 위로
                for (int i = 0; i < arr[p.first][p.second] && p.first - i >= 1 ; i++) {
                    q.push({p.first - i, p.second});
                }
            }
            fall[p.first][p.second] = 1;
            answer++;
        }
    }

//    cout << answer << "\n";
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            if (fall[i][j]) {
//                cout << "F ";
//            } else {
//                cout << "S ";
//            }
//        }
//        cout << "\n";
//    }
//    cout << "\n\n\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++) { // 세로로 몇 번째
        for (int j = 1; j <= m; j++) { // 가로로 몇 번째
            cin >> arr[i][j];
        }
    }

    int x, y;
    char d;
    for (int i = 0; i < r; i++) {
        cin >> x >> y >> d;
        attack(x, y, d);
        cin >> x >> y;
        fall[x][y] = 0;
    }

    cout << answer << "\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (fall[i][j]) {
                cout << "F ";
            } else {
                cout << "S ";
            }
        }
        cout << "\n";
    }

    return 0;
}