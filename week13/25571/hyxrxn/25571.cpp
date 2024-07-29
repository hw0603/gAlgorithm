#include <iostream>
using namespace std;

int t, n;
int arr[100001];
int connect;
bool increase;
long long answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        if (n == 1) {
            cin >> arr[0];
            cout << "0\n";
            continue;
        }
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        connect = 0;
        answer = 0;

        for (int j = 0; j < n - 1; j++) { // j번째와 j+1번째 비교
            if (connect == 0) { // 이전까지 연결된게 없다면 새로 확인
                if (arr[j] < arr[j + 1]) {
                    increase = true;
                    connect++;
                } else if (arr[j] > arr[j + 1]) {
                    increase = false;
                    connect++;
                }
                continue;
            }

            if (increase && arr[j] > arr[j + 1]) {
                increase = false;
                connect++;
            } else if (!increase && arr[j] < arr[j + 1]) {
                increase = true;
                connect++;
            } else { // 이번에 연결이 새로 시작
                answer += (long long)connect * (connect + 1) / 2; // 이전까지의 결과를 더해줌
                connect = 0;
                if (arr[j] < arr[j + 1]) {
                    increase = true;
                    connect++;
                } else if (arr[j] > arr[j + 1]) {
                    increase = false;
                    connect++;
                }
            }
        }
        answer += (long long)connect * (connect + 1) / 2;
        cout << answer << "\n";
    }

    return 0;
}
