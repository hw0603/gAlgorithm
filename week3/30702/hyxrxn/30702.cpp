#include <iostream>
using namespace std;

char A[50][50];
char B[50][50];

int main() {
    int n, m;
    cin >> n >> m;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            A[i][j] = s[j];
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            B[i][j] = s[j];
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (B[i][j] != B[i + 1][j] && A[i][j] == A[i + 1][j]) {
                cout << "NO";
                return 0;
            }
            if (B[i][j] != B[i][j + 1] && A[i][j] == A[i][j + 1]) {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";
    return 0;
}