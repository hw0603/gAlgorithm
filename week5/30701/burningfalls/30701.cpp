#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); ios_base::sync_with_stdio(0);
#define ll long long

int main() {
    FASTIO;
    ll N, D;
    cin >> N >> D;
    vector<vector<ll>> v(2, vector<ll>());
    for(int i = 0; i < N; i++) {
        ll A, X;
        cin >> A >> X;
        v[A - 1].push_back(X);
    }
    
    for(int i = 0; i < 2; i++) {
        sort(v[i].begin(), v[i].end());
    }
    
    int cnt = 0;
    ll power = D;
    int idx = 0;
    for(int i = 0; i < v[0].size(); i++) {
        while(idx < v[1].size() && power <= v[0][i]) {
            power *= v[1][idx];
            idx++;
        }
        if (power > v[0][i]) {
            power += v[0][i];
            cnt++;
        }
    }
    
    cout << cnt + v[1].size() << "\n";
    
    return 0;
}






