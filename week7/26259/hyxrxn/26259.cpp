#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[1001][1001];
int X1, X2, Y1, Y2;
int wall[1001][1001] = {0};
bool x, y;

int answer[1001][1001];

int calx(int i, int j) {
    if (i == 0) { // 첫 세로줄
        return -10000000;
    }
    if (x && wall[i][j]) { // 바로 위에 벽
        return -10000000;
    }
    if (arr[i][j] == -10000000) {
        return -10000000;
    }
    return answer[i - 1][j] + arr[i][j];
}

int caly(int i, int j) {
    if (j == 0) {
        return -10000000;
    }
    if (y && wall[i][j]) {
        return -10000000;
    }
    if (arr[i][j] == -10000000) {
        return -10000000;
    }
    return answer[i][j - 1] + arr[i][j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> X1 >> Y1 >> X2 >> Y2;

    if ((X1 == 0 && X2 == n && Y1 != 0 && Y1 != m) || (X1 == n && X2 == 0 && Y1 != 0 && Y2 != m)
        || (Y1 == 0 && Y2 == m && X1 != 0 && X1 != n) || (Y1 == m && Y2 == 0 && X1 != 0 && X1 != n)) {
        cout << "Entity";
        return 0;
    }

    if (X1 != X2) { // 벽이 세로로
        x = false;
        y = true;
        int d = max(X1, X2);
        X1 = min(X1, X2);
        X2 = d;
        for (int i = X1; i < X2; i++) {
            wall[i][Y1] = 1;
        }
        if (X1 == 0 && Y1 != 0) {
            for (int i = 0; i < X2; i++) {
                for (int j = Y1; j < m; j++) {
                    arr[i][j] = -10000000;
                }
            }
        }
    } else { // 벽이 가로로
        x = true;
        y = false;
        int d = max(Y1, Y2);
        Y1 = min(Y1, Y2);
        Y2 = d;
        for (int i = Y1; i < Y2; i++) {
            wall[X1][i] = 1;
        }
        if (Y1 == 0 && X1 != 0) {
            for (int i = X1; i < n; i++) {
                for (int j = 0; j < Y2; j++) {
                    arr[i][j] = -10000000;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                answer[i][j] = arr[i][j];
            } else {
                answer[i][j] = max(calx(i, j), caly(i, j));
            }
//            cout << calx(i, j) << " " << caly(i, j) << " " << answer[i][j] << endl;
        }
//        cout << endl;
    }

    cout << answer[n - 1][m - 1];
    return 0;
}
