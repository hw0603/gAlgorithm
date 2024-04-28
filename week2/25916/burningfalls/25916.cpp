#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); ios_base::sync_with_stdio(0);
#define ll long long

int main() {
    FASTIO;
    int N, M;
    cin >> N >> M;
    vector<ll> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    int left = 0, right = 0;
    ll maxi = 0;
    ll sum = v[0];
    while(right < N) {
        if (sum <= M) {
            maxi = max(maxi, sum);
            right++;
            sum += v[right];
        } else if (sum > M) {
            sum -= v[left];
            left++;
        }
    }
    cout << maxi << "\n";
    
    return 0;
}





