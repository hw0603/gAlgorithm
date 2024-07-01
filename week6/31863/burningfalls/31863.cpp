#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); ios_base::sync_with_stdio(0);
#define MAX 1002

int N, M;
vector<vector<char>> Map(MAX, vector<char>(MAX));
vector<vector<int>> visited(MAX, vector<int>(MAX, 0));
vector<vector<int>> accum(MAX, vector<int>(MAX, 0));
queue<pair<int, int>> q;
vector<int> dy = {-1, 1, 0, 0};
vector<int> dx = {0, 0, -1, 1};
int total_tower = 0;
int break_tower = 0;

void BFS() {
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if (visited[ny][nx]) continue;
            if (Map[ny][nx] == '|') {
                continue;
            } else if (Map[ny][nx] == '*') {
                visited[ny][nx] = 1;
                break_tower++;
                q.push({ny, nx});
            } else if (Map[ny][nx] == '#') {
                accum[ny][nx]++;
                if (accum[ny][nx] == 2) {
                    visited[ny][nx] = 1;
                    break_tower++;
                    q.push({ny, nx});
                }
            } else if (Map[ny][nx] == '.') {
                visited[ny][nx] = 1;
            }
        }
    }
}

int main() {
    FASTIO;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> Map[i][j];
            if (Map[i][j] == '*' || Map[i][j] == '#') {
                total_tower++;
            }
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if (Map[i][j] == '@') {
                for(int k = 0; k < 4; k++) {
                    int ny = i, nx = j;
                    for(int a = 0; a < 2; a++) {
                        ny += dy[k];
                        nx += dx[k];
                        if (ny < 0 || nx < 0 || ny >= N || nx >= M) break;
                        if (Map[ny][nx] == '|') {
                            break;
                        } else if (Map[ny][nx] == '*') {
                            visited[ny][nx] = 1;
                            break_tower++;
                            q.push({ny, nx});
                        } else if (Map[ny][nx] == '#') {
                            accum[ny][nx]++;
                            if (accum[ny][nx] == 2) {
                                visited[ny][nx] = 1;
                                break_tower++;
                                q.push({ny, nx});
                            }
                        }
                    }
                }
            }
        }
    }
    
    BFS();
    
    cout << break_tower << " " << total_tower - break_tower << "\n";
    
    
    return 0;
}








