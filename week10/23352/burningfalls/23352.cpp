#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MAX 52

int N, M;
vector<vector<int>> Map(MAX, vector<int>(MAX));
vector<int> dy = {-1, 1, 0, 0};
vector<int> dx = {0, 0, -1, 1};
int length = 0;
int maxi = 0;

void BFS(int sy, int sx) {
    vector<vector<int>> visited(N, vector<int>(M, 0));
    
    queue<pair<int, int>> q;
    q.push({sy, sx});
    visited[sy][sx] = 1;
    
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        if (length < visited[y][x]) {
            length = visited[y][x];
            if (sy == y && sx == x) {
                maxi = Map[sy][sx];
            } else {
                maxi = Map[sy][sx] + Map[y][x];
            }
        } else if (length == visited[y][x]) {
            if (sy == y && sx == x) {
                maxi = max(maxi, Map[y][x]);
            } else {
                maxi = max(maxi, Map[sy][sx] + Map[y][x]);
            }
        }
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if (visited[ny][nx]) continue;
            if (Map[ny][nx] == 0) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
}

int main() {
    FASTIO;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> Map[i][j];
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if (Map[i][j] == 0) continue;
            BFS(i, j);
        }
    }
    
    cout << maxi << "\n";

    return 0;
}
