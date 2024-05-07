#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); ios_base::sync_with_stdio(0);
#define ll long long

int main() {
    FASTIO;
    int M, N;
    cin >> M >> N;
    vector<int> L(N);
    for(int i = 0; i < N; i++) {
        cin >> L[i];
    }
    
    int left = 1, right = 1e9;
    int ans = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
        ll sum = 0;
        for(int i = 0; i < N; i++) {
            sum += L[i] / mid;
        }
        if (sum >= M) {
            ans = mid;
            left = mid + 1;
        } else if (sum < M) {
            right = mid - 1;
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}






