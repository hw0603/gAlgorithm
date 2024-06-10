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
            
            // 하나의 방향으로 쭉 나아가는데
            // 더 이상 나아가지 못하면(장애물을 만나거나 범위를 벗어나면) 반복문 탈출
            // 학생을 발견한 경우 바로 false 리턴 (함수로 뺐기 때문에 편하게 리턴 가능)
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
    
    // 정확히 3개의 장애물 설치
    // DFS나 순열, 조합과 같은 방법이 있지만,
    // 2개 혹은 3개를 다루는 경우, 그냥 for문이 더 편하다. (구현도 쉽고 보기도 쉬움)
    for(int i = 0; i < len; i++) {
        for(int j = i + 1; j < len; j++) {
            for(int k = j + 1; k < len; k++) {
                // 대신 이 안에서 로직을 수행하려면
                // i, j, k 사용 불가능하고 flag를 통한 break 관리가 까다로움
                // 그래서 주로 함수로 빼서 사용
                
                vector<int> tmp = {i, j, k};
                if (Cant_Install(tmp)) continue;
                Make_Obstacle(tmp);
                bool flag = Avoid();
                
                // if (flag) ans = true; 를
                // 아래와 같이 줄여서 쓸 수 있다.
                // flag가 하나라도 true면, ans가 true가 되는 원리
                ans |= flag;
                
                // 하나의 경우에 대해서 장애물을 설치해서
                // 전역변수를 변경했으므로(Make_Obstacle),
                // 반드시 원상태로 돌려 놓아야 한다(Delete_Obstacle)
                Delete_Obstacle(tmp);
            }
        }
    }
    
    cout << (ans ? "YES" : "NO") << "\n";
    
    return 0;
}

