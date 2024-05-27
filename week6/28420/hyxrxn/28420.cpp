#include <iostream>
#include <algorithm>
using namespace std;

int arr[301][301];
int n_sum[301][301] = {0};
int m_sum[301][301] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;

    for (int i = 1; i <= n; i++) { // 세로
        for (int j = 1; j <= m; j++) { // 가로
            cin >> arr[i][j];
            m_sum[i][j] = m_sum[i][j - 1] + arr[i][j];
        }
    }

    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            n_sum[i][j] = n_sum[i - 1][j] + arr[i][j];
        }
    }

//    for (int i = 1; i <= n; i++) { // 세로
//        for (int j = 1; j <= m; j++) { // 가로
//            cout << n_sum[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    for (int i = 1; i <= n; i++) { // 세로
//        for (int j = 1; j <= m; j++) { // 가로
//            cout << m_sum[i][j] << " ";
//        }
//        cout << endl;
//    }

    int mini = 100000000;
    int cur;
    // 시작점 1, 1 부터 n - a + 1, m - (b + c) + 1 까지 가능
    for (int i = 1; i <= n - a + 1; i++) {
        for (int j = 1; j <= m - (b + c) + 1; j++) {
            cur = 0;
            // 가로로 j ~ j + b + c - 1 까지의 합이 세로로 i ~ i + a - 1 까지
            for (int k = i; k <= i + a - 1; k++) {
                cur += m_sum[k][j + b + c - 1] - m_sum[k][j - 1];
            }
            // cout << cur << endl;
            mini = min(mini, cur);
        }
    }

    // 시작점 1, 1부터 n - (a + b) + 1, m - (c + a) + 1 까지 가능
    for (int i = 1; i <= n - (a + b) + 1; i++) {
        for (int j = 1; j <= m - (c + a) + 1; j++) {
            cur = 0;
            // 가로로 j ~ j + c - 1 까지의 합이 세로로 i ~ i + a - 1 까지
            for (int k = i; k <= i + a - 1; k++) {
                cur += m_sum[k][j + c - 1] - m_sum[k][j - 1];
            }
            // 세로로 i + a ~ i + a + b - 1 까지의 합이 가로로 j + c ~ j + c + a - 1 까지
            for (int k = j + c; k <= j + c + a - 1; k++) {
                cur += n_sum[i + a + b - 1][k] - n_sum[i + a - 1][k];
            }
            // cout << cur << endl;
            mini = min(mini, cur);
        }
    }

    // 시작점 1, 1부터 n - (a + c) + 1, m - (b + a) + 1 까지 가능
    for (int i = 1; i <= n - (a + c) + 1; i++) {
        for (int j = 1; j <= m - (b + a) + 1; j++) {
            cur = 0;
            // 가로로 j ~ j + b - 1 까지의 값이 세로로 i ~ i + a - 1 까지
            for (int k = i; k <= i + a - 1; k++) {
                cur += m_sum[k][j + b - 1] - m_sum[k][j - 1];
            }
            // 세로로 i + a ~ i + a + c - 1 까지의 합이 가로로 j + b ~ j + b + a - 1 까지
            for (int k = j + b; k <= j + b + a - 1; k++) {
                cur += n_sum[i + a + c - 1][k] - n_sum[i + a - 1][k];
            }
            // cout << cur << endl;
            mini = min(mini, cur);
        }
    }

    cout << mini;

    return 0;
}