#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define ll long long

int main() {
    FASTIO;
    int N, Q;
    cin >> N >> Q;
    vector<ll> P(N + 1), sum(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        cin >> P[i];
    }
    sort(P.begin(), P.end());
    for(int i = 1; i <= N; i++) {
        sum[i] = sum[i - 1] + P[i];
    }
    
    for(int i = 0; i < Q; i++) {
        ll num;
        cin >> num;
        int ub = upper_bound(P.begin(), P.end(), num) - P.begin();
        ll result = num * (ub - 1) - sum[ub - 1];
        result += (sum[N] - sum[ub - 1]) - num * (N - ub + 1);
        cout << result << "\n";
    }
    
    return 0;
}



