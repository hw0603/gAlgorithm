#include <iostream>
using namespace std;

int n, k, q, m, s, e;
int student[5005];
int sleep[5001];
int accept;
int num[5005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k >> q >> m;

    for (int i = 0; i < k; i++) {
        cin >> sleep[i];
        student[sleep[i]] = -1;
    }

    for (int i = 0; i < q; i++) {
        cin >> accept;
        if (student[accept] == 0) { // 아직 안 받았고 졸지도 않는 상태라면
            for (int j = accept; j <= n + 2; j += accept) {
                student[j] = 1;
            }
        }
    }

    for (int i = 0; i < k; i++) {
        student[sleep[i]] = 0; // 받았을지 모르지만 졸고있음
    }

    for (int i = 2; i <= n + 2; i++) {
        if (student[i]) {
            num[i] = num[i - 1] + 1;
        } else {
            num[i] = num[i - 1];
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> s >> e;
        cout << (e - s + 1) - (num[e] - num[s - 1]) << "\n";
    }

    return 0;
}
// 10 1 3 1
// 7
// 3 5 7
// 1 2 3 4 5 6 7 8 9 10 11 12
// 0 0 1 0 1 1 0 0 1 1  0  1

// 11%