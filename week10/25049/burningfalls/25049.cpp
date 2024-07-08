#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define ll long long
#define LINF 1e18

int main() {
    FASTIO;
    int N;
    cin >> N;
    vector<ll> P(N + 2);
    for(int i = 1; i <= N; i++) {
        cin >> P[i];
    }
    
    vector<ll> Ldp(N + 2, 0), Rdp(N + 2, 0);
    vector<ll> max_Ldp(N + 2, -LINF), max_Rdp(N + 2, -LINF);
    for(int i = 1; i <= N; i++) {
        Ldp[i] = max(P[i], Ldp[i - 1] + P[i]);
        max_Ldp[i] = max(max_Ldp[i - 1], Ldp[i]);
    }
    
    for(int i = N; i >= 1; i--) {
        Rdp[i] = max(P[i], Rdp[i + 1] + P[i]);
        max_Rdp[i] = max(max_Rdp[i + 1], Rdp[i]);
    }
    
    ll sum = 0;
    for(int i = 1; i <= N; i++) {
        sum += P[i];
    }
    
    ll ans = max(sum, sum + max_Ldp[N]);
    
    ll maxi = -LINF;
    for(int i = 2; i <= N; i++) {
        maxi = max(maxi, max_Ldp[i - 1] + max_Rdp[i]);
    }
    ans = max(ans, sum + maxi);
    
    cout << ans << "\n";

    return 0;
}
