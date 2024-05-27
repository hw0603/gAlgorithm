#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 1;
        return 0;
    }

    int front;
    cin >> front;
    int num = 1;

    int present;
    for (int i = 1; i < n - 1; i++) {
        cin >> present;
        if (present == front) {
            num++;
        } else {
            v.push_back({front, num}); // front 종류의 과일이 num 개 연속
            front = present;
            num = 1;
        }
    }

    cin >> present;
    if (present == front) {
        num++;
        v.push_back({front, num});
    } else {
        v.push_back({front, num});
        v.push_back({present, 1});
    }

    if (v.size() == 1) {
        cout << v[0].second;
        return 0;
    }

    int maxi = 0;
    int left = 0;
    int right = 1;
    int a, b, cur;
    while (right < v.size()) {
        a = v[left].first;
        b = v[right].first;
        cur = v[left].second + v[right].second;
        while (right < v.size()) {
            right++;
            if (right < v.size() && v[right].first == a || v[right].first == b) {
                cur += v[right].second;
            } else {
                break;
            }
        }
        maxi = max(maxi, cur);
        left = right - 1;
    }

    cout << maxi;
    return 0;
}
