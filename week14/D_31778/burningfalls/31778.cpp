#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define ll long long

int main() {
    FASTIO;
    int N, K;
    cin >> N >> K;
    vector<char> v(N + 1);
    for(int i = 1; i <= N; i++) {
        cin >> v[i];
    }
    
    int left = 1, right = N;
    while(K > 0) {
        while(left < N && v[left] == 'P') {
            left++;
        }
        while(right >= 0 && v[right] == 'C') {
            right--;
        }
        if (left >= right) break;
        swap(v[left], v[right]);
        K--;
    }
    
    vector<vector<ll>> dp(N + 1, vector<ll>(3, 0));
    for(int i = 1; i <= N; i++) {
        dp[i][0] = dp[i - 1][0] + (v[i] == 'P');
    }
    for(int i = 1; i <= N; i++) {
        dp[i][1] = dp[i - 1][1];
        if (v[i] == 'P') {
            dp[i][1] += dp[i - 1][0];
        }
    }
    for(int i = 1; i <= N; i++) {
        dp[i][2] = dp[i - 1][2];
        if (v[i] == 'C') {
            dp[i][2] += dp[i - 1][1];
        }
    }
    
    cout << dp[N][2] << "\n";
    
    return 0;
}




