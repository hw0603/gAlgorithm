#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iomanip>

using namespace std;

int n, m, r;
vector<int> location;
vector<int> length;
set<int> diff;
int maxi = 0;

void bs(int base) {
    int lower = 0;
    int upper = m - 1;
    while (lower <= upper) {
        int mid = (lower + upper) / 2;
        if (base * length[mid] <= r) {
            lower = mid + 1;
            maxi = max(maxi, base * length[mid]);
        } else {
            upper = mid - 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> r;
    r *= 2;

    int dummy;
    for (int i = 0; i < n; i++) {
        cin >> dummy;
        location.push_back(dummy);
    }
    sort(location.begin(), location.end());

    for (int i = 0; i < m; i++) {
        cin >> dummy;
        length.push_back(dummy);
    }
    sort(length.begin(), length.end());

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            diff.insert(location[j] - location[i]);
        }
    }

    for (set<int>::iterator iter = diff.begin(); iter != diff.end(); iter++) {
        bs(*iter);
    }

    if (maxi == 0) {
        cout << -1;
    } else {
        cout << fixed << setprecision(1);
        cout << (double) maxi / 2;
    }

    return 0;
}