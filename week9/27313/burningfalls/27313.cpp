#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(0); cout.tie(0);
#define ll long long

int main() {
    FASTIO;
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> L(N);
    for(int i = 0; i < N; i++) {
        cin >> L[i];
    }
    
    sort(L.begin(), L.end());
    
    int left = 1, right = N;
    int ans = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
        ll sum = 0;
        for(int i = mid - 1; i >= 0; i -= K) {
            sum += L[i];
        }
        if (sum <= M) {
            ans = mid;
            left = mid + 1;
        } else if (sum > M) {
            right = mid - 1;
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}


