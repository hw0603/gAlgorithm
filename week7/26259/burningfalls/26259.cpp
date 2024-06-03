#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(0); cout.tie(0);
#define INF 1e9

int main() {
    FASTIO;
    int N, M;
    cin >> N >> M;
    vector<vector<int>> Map(N + 1, vector<int>(M + 1));
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, -INF));
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> Map[i][j];
        }
    }
    
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    
    dp[1][1] = Map[1][1];
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if (i == 1 && j == 1) continue;
            int top = -INF, left = -INF;
            if (!(x1 == x2 && i - 1 == x1 && y1 < j && j <= y2)) {
                top = dp[i - 1][j];
            }
            if (!(y1 == y2 && j - 1 == y1 && x1 < i && i <= x2)) {
                left = dp[i][j - 1];
            }
            
            dp[i][j] = max(top, left);
            if (dp[i][j] != -INF) {
                dp[i][j] += Map[i][j];
            }
        }
    }
    
    if (dp[N][M] == -INF) {
        cout << "Entity";
    } else {
        cout << dp[N][M];
    }
    cout << "\n";
    
    return 0;
}


