#include <iostream>

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    int low;
    cin >> low;
    int res = 0;
    cout << res << ' ';
    for (int i = 0; i < n-1; ++i) {
        int input;
        cin >> input;
        if (input < low) {
            low = input;
            cout << res << ' ';
            continue;
        }
        int tmp = input - low;
        res = max(tmp, res);
        cout << res << ' ';
    }
}
