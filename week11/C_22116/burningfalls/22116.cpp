#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MAX 1001
#define INF 1e9

int N;
vector<vector<int>> Map(MAX, vector<int>(MAX));

bool Calc(int t) {
    queue<pair<int, int>> q;
    vector<vector<int>> visited(MAX, vector<int>(MAX, 0));
    vector<int> dy = {-1, 1, 0, 0};
    vector<int> dx = {0, 0, -1, 1};
    q.push({0, 0});
    visited[0][0] = 1;
    
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (y == N - 1 && x == N - 1) {
            return true;
        }
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            if (visited[ny][nx]) continue;
            if (abs(Map[ny][nx] - Map[y][x]) > t) continue;
            visited[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
    
    return false;
}

int main() {
    FASTIO;
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> Map[i][j];
        }
    }
    
    int left = 0, right = INF;
    int ans = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
        if (Calc(mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << "\n";
    
    return 0;
}
