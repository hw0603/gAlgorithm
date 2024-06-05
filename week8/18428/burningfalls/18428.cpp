#include <bits/stdc++.h>
using namespace std;

#define MAX 6

int N;
vector<vector<char>> Map(MAX, vector<char>(MAX));
vector<pair<int, int>> teachers;
vector<int> dy = {-1, 1, 0, 0};
vector<int> dx = {0, 0, -1, 1};

bool Cant_Install(vector<int>& idx) {
    for(int i = 0; i < idx.size(); i++) {
        if (Map[idx[i] / N][idx[i] % N] != 'X') {
            return true;
        }
    }
    return false;
}

void Make_Obstacle(vector<int>& idx) {
    for(int i = 0; i < idx.size(); i++) {
        Map[idx[i] / N][idx[i] % N] = 'O';
    }
}

void Delete_Obstacle(vector<int>& idx) {
    for(int i = 0; i < idx.size(); i++) {
        Map[idx[i] / N][idx[i] % N] = 'X';
    }
}

bool Avoid() {
    for(int i = 0; i < teachers.size(); i++) {
        int y = teachers[i].first;
        int x = teachers[i].second;
        
        for(int j = 0; j < 4; j++) {
            int ny = y, nx = x;
            while(true) {
                ny = ny + dy[j];
                nx = nx + dx[j];
                if (ny < 0 || nx < 0 || ny >= N || nx >= N) break;
                if (Map[ny][nx] == 'O') break;
                if (Map[ny][nx] == 'S') {
                    return false;
                }
            }
        }
    }
    
    return true;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> Map[i][j];
            if (Map[i][j] == 'T') {
                teachers.push_back({i, j});
            }
        }
    }
    
    int len = N * N;
    bool ans = false;
    for(int i = 0; i < len; i++) {
        for(int j = i + 1; j < len; j++) {
            for(int k = j + 1; k < len; k++) {
                vector<int> tmp = {i, j, k};
                if (Cant_Install(tmp)) continue;
                Make_Obstacle(tmp);
                bool flag = Avoid();
                ans |= flag;
                Delete_Obstacle(tmp);
            }
        }
    }
    
    cout << (ans ? "YES" : "NO") << "\n";
    
    return 0;
}

