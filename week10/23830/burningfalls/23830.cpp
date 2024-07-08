#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define ll long long
#define LINF 1e18

int main() {
    FASTIO;
    ll N, P, Q, R, S;
    cin >> N;
    vector<ll> A(N);
    ll sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    cin >> P >> Q >> R >> S;
    sort(A.begin(), A.end());
    
    ll ans = -1;
    ll left = 1, right = 100001;
    while(left <= right) {
        ll mid = (left + right) / 2;
        ll lb = lower_bound(A.begin(), A.end(), mid) - A.begin();
        ll ub = upper_bound(A.begin(), A.end(), mid + R) - A.begin();
        ll tmp = sum + Q * lb - P * (N - ub);
        if (tmp < S) {
            left = mid + 1;
        } else if (tmp >= S) {
            ans = mid;
            right = mid - 1;
        }
    }
    
    cout << ans << "\n";

    return 0;
}

