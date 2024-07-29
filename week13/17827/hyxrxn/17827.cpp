#include <iostream>
using namespace std;

int n, m, v;
int arr[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> v;
    for (int i = 1; i <=n; i++) {
        cin >> arr[i];
    }

    int k;
    for (int i = 0; i < m; i++) {
        cin >> k;
        k++;
        if (k > n) {
            k -= (v - 1);
            k %= (n - (v - 1));
            if (k == 0) {
                k = n;
            } else {
                k += (v - 1);
            }
        }
        cout << arr[k] << "\n";
    }

    return 0;
}