#include <bits/stdc++.h>
using namespace std;

struct NODE {
    int light;
    int y;
    int x;
    
    // 우선순위 큐 상에는 light 값이 가장 큰 값이 pq.top에 위치
    bool operator<(const NODE &n) const {
        return light < n.light;
    }
};

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> Map(H, vector<int>(W));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> Map[i][j];
        }
    }
    
    priority_queue<NODE> pq;
    vector<vector<int>> visited(H, vector<int>(W, 0));
    int cnt = 0;
    vector<int> dy = {-1, 1, 0, 0};
    vector<int> dx = {0, 0, -1, 1};
    
    // 조명을 뽑아냄 (주변보다 밝기가 크거나 같음)
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if (Map[i][j] < 1) continue;
            bool flag = true;
            for(int k = 0; k < 4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
                if (Map[i][j] < Map[ny][nx]) {
                    flag = false;
                }
            }
            if (flag) {
                visited[i][j] = Map[i][j];
                pq.push({Map[i][j], i, j});
                // 전구의 개수
                cnt++;
            }
        }
    }
    
    // light가 큰 값부터 차례대로 처리
    while(!pq.empty()) {
        int y = pq.top().y;
        int x = pq.top().x;
        pq.pop();
        // light가 1이면 처리하지 않도록 함
        if (visited[y][x] == 1) continue;
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
            if (visited[ny][nx]) continue;
            if (Map[ny][nx] == -1) continue;
            visited[ny][nx] = visited[y][x] - 1;
            // light가 1이면 처리하지 않도록 함
            if (visited[ny][nx] == 1) continue;
            pq.push({visited[ny][nx], ny, nx});
        }
    }
    
    bool ans = true;
    // 진짜 Map과 조명을 통해 만든 visited가 다르면 false
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if (Map[i][j] == -1) continue;
            if (Map[i][j] != visited[i][j]) {
                ans = false;
            }
        }
    }
    
    cout << (ans ? cnt : -1) << "\n";
    
    return 0;
}
