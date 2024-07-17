#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;

bool compare(pair<int, int> p1, pair<int, int> p2) { // x값이 클수록 -> y값이 클수록
    if (p1.first == p2.first) {
        return p1.second > p2.second;
    }
    return p1.first > p2.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        a /= 2;
        b /= 2;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), compare);

    int w = v[0].first; // 현재 x값 (점점 작아짐)
    int h = v[0].second; // 현재 y값 (점점 커짐)
    long long sum = w * h;
    for (int i = 1; i < n; i++) {
        cout << v[i].first << " " << v[i].second << endl;
        if (v[i].first == w || v[i].second <= h) {
            cout << "skip" << endl;
            continue;
        }
        sum += v[i].first * (v[i].second - h);
        w = v[i].first;
        h = v[i].second;
    }

    cout << sum * 4;
    return 0;
}

// 24 * 4
/*
8
2 12
6 10
4 8
8 8
4 6
10 6
6 4
12 2
*/