#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); ios_base::sync_with_stdio(0);
#define MAX 1002

int main() {
    FASTIO;
    int R, C, N;
    cin >> R >> C;
    cin >> N;
    vector<int> H(N);
    vector<vector<int>> v(R + 1, vector<int>(C + 1, 0));
    for(int i = 0; i < N; i++) {
        cin >> H[i];
    }
    sort(H.begin(), H.end());
    
    int cnt = 0;
    int idx = 0;
    for(int i = 1; i <= R; i++) {
        if (idx >= N) {
            break;
        }
        for(int j = 1; j <= C; j++) {
            while(idx < N && v[i - 1][j] >= H[idx]) {
                idx++;
            }
            if (idx >= N) {
                break;
            }
            v[i][j] = H[idx];
            cnt++;
            idx++;
        }
    }
    
    cout << cnt << "\n";
    
    return 0;
}





