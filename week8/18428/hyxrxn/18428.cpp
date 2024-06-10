#include <iostream>
using namespace std;

int n;
char arr[7][7];

void see() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 'T') {
                for (int k = i + 1; k < n; k++) {
                    if (arr[k][j] == 'S') { // 실패
                        return;
                    } else if (arr[k][j] == 'O' || arr[k][j] == 'T') { // 막혀서 그만 봐도 됨
                        break;
                    }
                }
                for (int k = i - 1; k >= 0; k--) {
                    if (arr[k][j] == 'S') { // 실패
                        return;
                    } else if (arr[k][j] == 'O' || arr[k][j] == 'T') { // 막혀서 그만 봐도 됨
                        break;
                    }
                }
                for (int k = j + 1; k < n; k++) {
                    if (arr[i][k] == 'S') { // 실패
                        return;
                    } else if (arr[i][k] == 'O' || arr[i][k] == 'T') { // 막혀서 그만 봐도 됨
                        break;
                    }
                }
                for (int k = j - 1; k >= 0; k--) {
                    if (arr[i][k] == 'S') { // 실패
                        return;
                    } else if (arr[i][k] == 'O' || arr[i][k] == 'T') { // 막혀서 그만 봐도 됨
                        break;
                    }
                }
            }
        }
    }
    cout << "YES";
    exit(0);
}

void makeO(int count) {
    if (count == 3) {
        see();
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 'X') {
                arr[i][j] = 'O';
                makeO(count + 1);
                arr[i][j] = 'X';
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    makeO(0);

    cout << "NO";
    return 0;
}
