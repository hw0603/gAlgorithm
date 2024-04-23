#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); ios_base::sync_with_stdio(0);

int main() {
    FASTIO;
    int N, M;
    cin >> N >> M;
    vector<pair<string, int>> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }
    
    for(int i = 1; i <= M; i++) {
        int num;
        cin >> num;
        
        int left = 0, right = N - 1;
        int ans = 0;
        while(left <= right) {
            int mid = (left + right) / 2;
            if (num <= v[mid].second) {
                ans = mid;
                right = mid - 1;
            } else if (num > v[mid].second) {
                left = mid + 1;
            }
        }
        
        cout << v[ans].first << "\n";
    }
    
    return 0;
}




