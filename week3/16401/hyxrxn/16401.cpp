#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int m, n;

bool ok(int middle) {
    if (middle == 0) {
        return false;
    }
    int num = 0;
    for (int i = n - 1; i >= 0; i--) {
        num += v[i] / middle;

        cout << "i = " << i << ", num = " << num << endl;

        if (num >= m) {

            cout << "middle = " << middle << ", 성공" << endl;

            return true;
        }
    }

    cout << "middle = " << middle << ", 실패" << endl;

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m >> n;

    int dummy;
    for (int i = 0; i < n; i++) {
        cin >> dummy;
        v.emplace_back(dummy);
    }
    sort(v.begin(), v.end());

    int l = 0;
    int h = v[n - 1];
    int middle;
    int answer = 0;
    while (l <= h) {
        middle = (l + h + 1) / 2;
        if (ok(middle)) {
            l = middle + 1;
            answer = middle;
        } else {
            h = middle - 1;
        }
    }

    cout << answer;

    return 0;
}