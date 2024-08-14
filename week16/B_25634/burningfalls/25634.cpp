#include <bits/stdc++.h>
using namespace std;
 
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define ll long long

int main() {
    FASTIO;
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    ll sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> B[i];
        if (B[i] == 1) {
            sum += A[i];
            A[i] *= -1;
        }
    }
    
    vector<ll> dp(N);
    ll maxi = A[0];
    dp[0] = A[0];
    for(int i = 1; i < N; i++) {
        dp[i] = max(A[i], dp[i - 1] + A[i]);
        maxi = max(maxi, dp[i]);
    }
    
    cout << sum + maxi << "\n";
    
    return 0;
}


