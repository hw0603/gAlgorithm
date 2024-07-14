#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define ll long long
#define INF (long)2e9

struct NODE {
    ll x;
    ll y;
    ll len;
};

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    FASTIO;
    int N;
    cin >> N;
    vector<pair<ll, ll>> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
        v[i].first /= 2;
        v[i].second /= 2;
    }
    sort(v.begin(), v.end(), compare);
    
    vector<NODE> t;
    t.push_back({INF, 0, 0});
    for(int i = 0; i < N; i++) {
        if (t.back().x > v[i].first) {
            t.push_back({v[i].first, v[i].second, v[i].second - t.back().y});
            continue;
        }
        
        while(t.back().x <= v[i].first) {
            t.pop_back();
        }
        t.push_back({v[i].first, v[i].second, v[i].second - t.back().y});
    }
    
    ll ans = 0;
    for(int i = 0; i < t.size(); i++) {
        ans += t[i].x * t[i].len;
    }
    
    cout << ans * 4 << "\n";

    return 0;
}
