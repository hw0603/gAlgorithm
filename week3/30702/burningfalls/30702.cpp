#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); ios_base::sync_with_stdio(0);
#define MAX 52

int N, M;
vector<vector<char>> v1(MAX, vector<char>(MAX));
vector<vector<char>> v2(MAX, vector<char>(MAX));
vector<vector<int>> visited(MAX, vector<int>(MAX, 0));
vector<int> dy = {-1, 1, 0, 0};
vector<int> dx = {0, 0, -1, 1};

bool BFS(int sy, int sx) {
    queue<pair<int, int>> q;
    q.push({sy, sx});
    visited[sy][sx] = 1;
    
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if (visited[ny][nx]) continue;
            if (v1[y][x] != v1[ny][nx]) continue;
            if (v2[y][x] != v2[ny][nx]) {
                return false;
            }
            visited[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
    return true;
}

int main() {
    FASTIO;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> v1[i][j];
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> v2[i][j];
        }
    }
    
    bool flag = true;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if (visited[i][j]) continue;
            flag &= BFS(i, j);
        }
    }

    cout << (flag ? "YES" : "NO") << "\n";
    
    return 0;
}






