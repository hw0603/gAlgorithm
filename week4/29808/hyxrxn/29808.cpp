#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

bool compares(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int s;
    cin >> s;

    if (s % 4763 != 0) {
        cout << "0";
        return 0;
    }

    s /= 4763;

    for (int KmE = 0; KmE <= 200 ; KmE++) {
        if ((s - KmE * 508) >= 0 && (s - KmE * 508) % 212 == 0 && (s - KmE * 508) / 212 <= 200) {
            v.push_back({KmE, (s - KmE * 508) / 212});
        }
        else if ((s - KmE * 508) >= 0 && (s - KmE * 508) % 305 == 0 && (s - KmE * 508) / 305 <= 200) {
            v.push_back({KmE, (s - KmE * 508) / 305});
        }
        else if ((s - KmE * 108) >= 0 && (s - KmE * 108) % 212 == 0 && (s - KmE * 108) / 212 <= 200) {
            v.push_back({KmE, (s - KmE * 108) / 212});
        }
        else if ((s - KmE * 108) >= 0 && (s - KmE * 108) % 305 == 0 && (s - KmE * 108) / 305 <= 200) {
            v.push_back({KmE, (s - KmE * 108) / 305});
        }
    }

    sort(v.begin(), v.end(), compares);

    cout << v.size() << "\n";
    for (const auto &item: v) {
        cout << item.first << " " << item.second << "\n";
    }

    return 0;
}