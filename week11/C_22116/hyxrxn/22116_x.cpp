// 갈 수 있는 길을 모두 가본 코드...
// 너무 열심히 짰던 기억에 남겨둡니다...

#include <iostream>
#include <cstdlib>
using namespace std;

int n;
int arr[1001][1001];
int visit[1001][1001] = {0};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int nx, ny;
int answer = 1000000001;

void dfs(int x, int y, int maxi) {
    visit[x][y] = 1;
    if (x == n - 1 && y == n - 1) {
        answer = min(answer, maxi);
        visit[x][y] = 0;
        return;
    }
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < n && visit[nx][ny] == 0) {
//            visit[nx][ny] = 1;
            maxi = max(maxi, abs(arr[nx][ny] - arr[x][y]));
            dfs(nx, ny, maxi);
//            visit[nx][ny] = 0;
        }
    }
    visit[x][y] = 0;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

//    visit[0][0] = 1;
    dfs(0, 0, 0);

    cout << answer;
    return 0;
}