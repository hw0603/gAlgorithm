#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    long long d;
    cin >> n >> d;

    v[1].push_back(0);
    v[2].push_back(0);
    int num, dummy;
    for (int i = 0; i < n; i++) {
        cin >> num >> dummy;
        v[num].push_back(dummy);
    }

    sort(v[1].begin(), v[1].end());
    sort(v[2].begin(), v[2].end());

    int index = 1;
    for (int i = 1; i <= v[1].size() - 1; i++) { // i번째 몬스터 방 돌파 시도
        while (d <= v[1][i]) {
            if (index > v[2].size() - 1) { // 장비 소진
                cout << i - 1 + v[2].size() - 1; // i - 1개의 몬스터 방, 모든 장비 방 돌파
                return 0;
            }
            d *= v[2][index];
            index++;
        }
        d += v[1][i];
    }

    cout << n;
    return 0;
}
