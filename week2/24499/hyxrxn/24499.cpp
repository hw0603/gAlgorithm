#include <iostream>
#include <algorithm>
using namespace std;

int arr[100002];

int main() {
    int n, k;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max = 0;
    for (int i = 0; i < k; i++) {
        max += arr[i];
    }

    int present = max;
    for (int i = 1; i < n; i++) {
        present = present - arr[i - 1] + arr[(i + k - 1) % n];
        max = std::max(max, present);
    }

    cout << max;

    return 0;
}
