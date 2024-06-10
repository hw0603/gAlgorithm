#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, t;
vector<pair<int, int>> v;
int answer[1001][1001] = {0};
int s = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> t;
    int d, m;
    for (int i = 1; i <= n; i++) { // i번째 과제까지 고려
        cin >> d >> m;
        s += m;
        for (int j = 1; j <= t; j++) { // j날 소요시 최대 이득
            if (d > j) { // j날 안에 못풀면
                answer[i][j] = answer[i - 1][j];
            } else { // 풀 수 있으면 갱신
                answer[i][j] = max(answer[i - 1][j], answer[i - 1][j - d] + m);
            }
        }
    }

    cout << s - answer[n][t];
    return 0;
}

