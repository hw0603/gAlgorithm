#include <iostream>
using namespace std;

int n;
int bright[202020];
int all = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> bright[i];
    }
    int light;
    for (int i = 0; i < n; i++) {
        cin >> light;
        if (light) {
            all += bright[i];
            bright[i] *= -1;
        }
    }

    int current = bright[0];
    int maxi = current;
    for (int i = 1; i < n; i++) {
        current = max(bright[i], current + bright[i]);
        maxi = max(maxi, current);
    }

    cout << all + maxi;

    return 0;
}