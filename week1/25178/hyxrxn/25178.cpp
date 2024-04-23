#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> v;

int main() {
    v.push_back('a');
    v.push_back('e');
    v.push_back('i');
    v.push_back('o');
    v.push_back('u');

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int l;
    string a, b;
    cin >> l >> a >> b;

    if (a[0] != b[0] || a[l - 1] != b[l - 1]) {
        cout << "NO";
        return 0;
    }

    vector<char> a_v, b_v, a_c, b_c;
    for (int i = 0; i < l; i++) {
        if (find(v.begin(), v.end(), a[i]) == v.end()) {
            a_c.push_back(a[i]);
        }
        else {
            a_v.push_back(a[i]);
        }
        if (find(v.begin(), v.end(), b[i]) == v.end()) {
            b_c.push_back(b[i]);
        }
        else {
            b_v.push_back(b[i]);
        }
    }

    sort(a_v.begin(), a_v.end());
    sort(b_v.begin(), b_v.end());

    if (a_v == b_v && a_c == b_c) {
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}
