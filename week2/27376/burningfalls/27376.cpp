#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); ios_base::sync_with_stdio(0);
#define ll long long

struct NODE {
    ll x;
    ll t;
    ll s;
    
    bool operator<(const NODE &n) const {
        return x < n.x;
    }
};

int main() {
    FASTIO;
    ll N, K;
    cin >> N >> K;
    vector<NODE> v(K + 1);
    v[0] = {0, 0, 0};
    for(int i = 1; i <= K; i++) {
        cin >> v[i].x >> v[i].t >> v[i].s;
    }
    sort(v.begin(), v.end());
    
    ll time = 0;
    for(int i = 1; i <= K; i++) {
        time += v[i].x - v[i - 1].x;
        time = max(time, v[i].s);
        
        ll tmp = (time - v[i].s) % (v[i].t * 2);
        if (v[i].t <= tmp && tmp < v[i].t * 2) {
            time += v[i].t * 2 - tmp;
        }
    }
    time += (N - v[K].x);
    
    cout << time << "\n";
    
    return 0;
}





