#include <iostream>
#include <algorithm>
using namespace std;

int n, m, x, y;
int error[500001];
int continueLine[500001];
int sum[500001] = {0}; // sum[0] = 0

bool able(int middle) {
    for (int i = 0; i <= (m + 1) - (middle + 1); i++) {
//        cout << sum[i + middle + 1] - sum[i] + middle << endl;
        if (sum[i + middle + 1] - sum[i] + middle >= x) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> error[i];
    }
    cin >> x >> y;

    continueLine[0] = error[0] - 1;
    sum[1] = continueLine[0];
//    cout << continueLine[0] << " " << sum[1] << endl;
    for (int i = 1; i <= m - 1; i++) {
        continueLine[i] = error[i] - error[i - 1] - 1;
        sum[i + 1] = sum[i] + continueLine[i];
//        cout << continueLine[i] << " " << sum[i + 1] << endl;
    }
    continueLine[m] = n - error[m - 1];
    sum[m + 1] = sum[m] + continueLine[m];
//    cout << continueLine[m] << " " << sum[m + 1] << endl;
//    for (int i = 0; i <= m + 1; i++) {
//        cout << sum[i] << endl;
//    }

    int lower = 0;
    int upper = m;
    int middle;
    int answer = m; // 내가 이만큼 고치면 x개 연속 가능
    while (lower <= upper) {
        middle = (lower + upper + 1) / 2;
        if (able(middle)) {
            answer = middle;
            upper = middle - 1;
        } else {
            lower = middle + 1;
        }
    }

    cout << m - max(answer, y);
    return 0;
}

/*
12 4
2 5 8 9
8 0
*/