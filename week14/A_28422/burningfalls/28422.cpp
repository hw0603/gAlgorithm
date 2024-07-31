#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define INF 2e9

int Calc(int x) {
    int cnt = 0;
    for(int i = 0; i < 10; i++) {
        if (x & (1 << i)) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    FASTIO;
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> dp(N, -INF);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    if (N == 1) {
        cout << 0 << "\n";
        return 0;
    }
    
    dp[1] = Calc(A[0] ^ A[1]);
    dp[2] = Calc(A[0] ^ A[1] ^ A[2]);
    for(int i = 3; i < N; i++){
        dp[i] = max(dp[i], dp[i - 2] + Calc(A[i - 1] ^ A[i]));
        dp[i] = max(dp[i], dp[i - 3] + Calc(A[i - 2] ^ A[i - 1] ^ A[i]));
    }
    cout << dp[N - 1] << "\n";
    
    return 0;
}




