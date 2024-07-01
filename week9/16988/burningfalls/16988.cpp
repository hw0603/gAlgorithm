#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(0); cout.tie(0);
#define MAX 22

struct NODE {
    int y;
    int x;
};

int N, M;
vector<vector<int>> Map(MAX, vector<int>(MAX));
vector<vector<int>> visited(MAX, vector<int>(MAX, 0));
vector<int> dy = {-1, 1, 0, 0};
vector<int> dx = {0, 0, -1, 1};

NODE Change(int idx) {
    int y = (idx - 1) / M + 1;
    int x = (idx - 1) % M + 1;
    return {y, x};
}

int BFS(int sy, int sx) {
    queue<NODE> q;
    visited[sy][sx] = 1;
    q.push({sy, sx});
    
    bool flag = true;
    int cnt = 1;
    while(!q.empty()) {
        NODE n = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = n.y + dy[i];
            int nx = n.x + dx[i];
            if (ny < 0 || nx < 0 || ny > N + 1 || nx > M + 1) continue;
            if (visited[ny][nx]) continue;
            if (Map[ny][nx] == 0) {
                flag = false;
            }
            if (Map[ny][nx] == 2) {
                cnt++;
                visited[ny][nx] = 1;
                q.push({ny, nx});
            }
        }
    }
    
    return (flag ? cnt : 0);
}

int Func() {
    visited = vector<vector<int>>(MAX, vector<int>(MAX, 0));
    
    int sum = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if (Map[i][j] != 2) continue;
            if (visited[i][j]) continue;
            sum += BFS(i, j);
        }
    }
    
    return sum;
}

int main() {
    FASTIO;
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> Map[i][j];
        }
    }
    for(int i = 1; i <= N; i++) {
        Map[i][0] = 1;
        Map[i][M + 1] = 1;
    }
    for(int j = 1; j <= M; j++) {
        Map[0][j] = 1;
        Map[N + 1][j] = 1;
    }
    
    int maxi = 0;
    for(int i = 1; i <= N * M; i++) {
        NODE p1 = Change(i);
        if (Map[p1.y][p1.x] != 0) continue;
        for(int j = i + 1; j <= N * M; j++) {
            NODE p2 = Change(j);
            if (Map[p2.y][p2.x] != 0) continue;
            
            Map[p1.y][p1.x] = 1;
            Map[p2.y][p2.x] = 1;
            maxi = max(maxi, Func());
            Map[p1.y][p1.x] = 0;
            Map[p2.y][p2.x] = 0;
        }
    }
    
    cout << maxi << "\n";
    
    return 0;
}


