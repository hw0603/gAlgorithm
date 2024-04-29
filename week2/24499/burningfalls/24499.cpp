#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); ios_base::sync_with_stdio(0);

int main() {
    FASTIO;
    int N, K;
    cin >> N >> K;
    vector<int> A(2 * N + 1);
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        A[i + N] = A[i];
    }
    
    vector<int> sum(2 * N + 1, 0);
    for(int i = 1; i <= 2 * N; i++) {
        sum[i] = sum[i - 1] + A[i];
    }
    
    int maxi = 0;
    for(int i = K; i <= 2 * N; i++) {
        maxi = max(maxi, sum[i] - sum[i - K]);
    }
    cout << maxi << "\n";
    
    return 0;
}





