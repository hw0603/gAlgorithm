#include <bits/stdc++.h>
using namespace std;
 
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define ll long long

int main() {
    FASTIO;
    ll N, L;
    cin >> N >> L;
    vector<ll> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    if (N == 1) {
        cout << 0 << "\n";
        return 0;
    }
    
    vector<ll> v1, v2;
    v1.push_back(v[0]);
    v2.push_back(v[1]);
    for(int i = 2; i < N; i++) {
        if (v1.back() <= v2.back()) {
            v1.push_back(v[i]);
        } else if (v1.back() > v2.back()) {
            v2.push_back(v[i]);
        }
    }
    
    vector<pair<ll, ll>> v3, v4;
    for(int i = 0; i < v1.size(); i++) {
        ll left = v1[i] - L;
        ll right = v1[i] + L;
        if (v3.empty() || v3.back().second < left) {
            v3.push_back({left, right});
        } else {
            v3.back().second = right;
        }
    }
    for(int i = 0; i < v2.size(); i++) {
        ll left = v2[i] - L;
        ll right = v2[i] + L;
        if (v4.empty() || v4.back().second < left) {
            v4.push_back({left, right});
        } else {
            v4.back().second = right;
        }
    }
    
    ll ans = 0;
    int idx1 = 0, idx2 = 0;
    while(idx1 < v3.size() && idx2 < v4.size()) {
        ll left = max(v3[idx1].first, v4[idx2].first);
        ll right = min(v3[idx1].second, v4[idx2].second);
        ans += max(0LL, right - left);
        if (v3[idx1].second <= v4[idx2].second) {
            idx1++;
        } else {
            idx2++;
        }
    }
    
    cout << ans << "\n";
    
    
    return 0;
}


