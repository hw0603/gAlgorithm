#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); ios_base::sync_with_stdio(0);

int main() {
    FASTIO;
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    vector<int> dp(N);
    int mini = v[0];
    dp[0] = 0;
    for(int i = 1; i < N; i++) {
        dp[i] = max(dp[i - 1], v[i] - mini);
        mini = min(mini, v[i]);
    }
    
    for(int i = 0; i < N; i++) {
        cout << dp[i] << " ";
    }
    cout << "\n";
    
    return 0;
}





