#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(0); cout.tie(0);
#define MAX 1002

// 이게 되네;;

int H, W;
vector<vector<int>> Map(MAX, vector<int>(MAX));
vector<int> dy = {-1, 1, 0, 0};
vector<int> dx = {0, 0, -1, 1};

// 절댓값이 0~1이 아닌 곳이 있으면, 미로 만들기 불가능
bool Check(int y, int x) {
    bool flag = true;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
        if (Map[ny][nx] == -1) continue;
        if (abs(Map[ny][nx] - Map[y][x]) > 1) {
            flag = false;
        }
    }
    return flag;
}

// 주변의 light보다 크거나 같으면 조명
bool Find(int y, int x) {
    bool flag = true;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
        if (Map[ny][nx] == -1) continue;
        if (Map[y][x] + 1 == Map[ny][nx]) {
            flag = false;
        }
    }
    return flag;
}

int main() {
    FASTIO;
    cin >> H >> W;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> Map[i][j];
        }
    }
    
    // 미로가 가능한지 확인
    bool flag = true;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if (Map[i][j] <= 0) continue;
            if (!Check(i, j)) {
                flag = false;
            }
        }
    }
    
    // 조명 개수 세기
    int cnt = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if (Map[i][j] <= 0) continue;
            cnt += Find(i, j);
        }
    }
    
    if (!flag) {
        cout << -1;
    } else if (flag) {
        cout << cnt;
    }
    cout << "\n";
    
    
    return 0;
}


