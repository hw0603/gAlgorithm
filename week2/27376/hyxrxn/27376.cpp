#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n, k;
int x[100002], t[100002], s[100002];
vector<tuple<int, int, int>> v;

long long waitingTime(int i, long long time) {
    if (time < get<2>(v[i])) {
        return get<2>(v[i]) - time;
    }
    if (((time - get<2>(v[i])) / get<1>(v[i])) % 2 == 0) {
        return 0;
    }
    return get<1>(v[i]) - (time - get<2>(v[i])) % get<1>(v[i]);
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> x[i] >> t[i] >> s[i];
        v.push_back({x[i], t[i], s[i]});
    }

    sort(v.begin(), v.end());

    long long time = 0;
    int now = 0;
    for (int i = 0; i < k; i++) {
        time += get<0>(v[i]) - now;
        now = get<0>(v[i]);
        time += waitingTime(i, time);
    }

    time += n - now;

    cout << time;

    return 0;
}
