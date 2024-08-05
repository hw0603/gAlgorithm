#include <iostream>
using namespace std;

int n;
int arr[100001];
int dp[100001]; // i번째 카드까지 가져갔을 때의 최고 점수

int count(int number) {
    int count = 0;
    while (number > 0) {
        if (number % 2 == 1) {
            count++;
        }
        number /= 2;
    }
    return count;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0] = 0;
    dp[1] = count(arr[0] ^ arr[1]);
    dp[2] = count(arr[0] ^ arr[1] ^ arr[2]);
    dp[3] = dp[1] + count(arr[2] ^ arr[3]);

    for (int i = 4; i < n; i++) {
        dp[i] = max(dp[i - 2] + count(arr[i - 1] ^ arr[i]),
                    dp[i - 3] + count(arr[i - 2] ^ arr[i - 1] ^ arr[i]));
    }

    cout << dp[n - 1];
    return 0;
}
