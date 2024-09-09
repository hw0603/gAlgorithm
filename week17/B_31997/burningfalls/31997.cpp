#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); ios_base::sync_with_stdio(0);

int main() {
    FASTIO;
    int N, M, T;
    cin >> N >> M >> T;
    vector<pair<int, int>> v(N + 1);
    for(int i = 1; i <= N; i++) {
        cin >> v[i].first >> v[i].second;
    }
    
    vector<int> sum(T + 1, 0);
    for(int i = 1; i <= M; i++) {
        int c, d;
        cin >> c >> d;
        int left = max(v[c].first, v[d].first);
        int right = min(v[c].second, v[d].second);
        if (left >= right) continue;
        sum[left]++;
        sum[right]--;
    }
    
    for(int i = 1; i <= T; i++) {
        sum[i] = sum[i - 1] + sum[i];
    }
    
    for(int i = 0; i < T; i++) {
        cout << sum[i] << "\n";
    }
    
    return 0;
}








