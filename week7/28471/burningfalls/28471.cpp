#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(0); cout.tie(0);
#define MAX 2002

int N;
vector<vector<char>> Map(MAX, vector<char>(MAX));
vector<vector<int>> visited(MAX, vector<int>(MAX, 0));
vector<int> dy = {-1, -1, -1, 0, 0, 1, 1};
vector<int> dx = {-1, 0, 1, -1, 1, -1, 1};

int BFS(int sy, int sx) {
    queue<pair<int, int>> q;
    q.push({sy, sx});
    visited[sy][sx] = 1;
    
    int cnt = 0;
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        cnt++;
        for(int i = 0; i < 7; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            if (visited[ny][nx]) continue;
            if (Map[ny][nx] == '#') continue;
            visited[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
    
    return cnt - 1;
}

int main() {
    FASTIO;
    cin >> N;
    int sy = 0, sx = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> Map[i][j];
            if (Map[i][j] == 'F') {
                sy = i;
                sx = j;
            }
        }
    }
    
    cout << BFS(sy, sx) << "\n";
    
    return 0;
}

