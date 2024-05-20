#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); ios_base::sync_with_stdio(0);
#define MAX 102

int N, M, R;
int score = 0;
vector<int> dy = {0, 0, 1, -1};
vector<int> dx = {1, -1, 0, 0};
vector<vector<int>> v(MAX, vector<int>(MAX));
vector<vector<char>> Map(MAX, vector<char>(MAX, 'S'));

int getDir(char d) {
    vector<char> dir = {'E', 'W', 'S', 'N'};
    for(int i = 0; i < 4; i++) {
        if (d == dir[i]) {
            return i;
        }
    }
    return 0;
}

void Func(int y, int x, int d) {
    int len = 1;
    while(y >= 1 && y <= N && x >= 1 && x <= M) {
        if (Map[y][x] == 'S' && len != 0) {
            Map[y][x] = 'F';
            len = max(len, v[y][x]);
            score++;
        }
        y += dy[d];
        x += dx[d];
        len = max(0, len - 1);
    }
}

int main() {
    FASTIO;
    cin >> N >> M >> R;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> v[i][j];
        }
    }

    for(int t = 1; t <= R; t++) {
        int Y, X;
        char D;
        cin >> Y >> X >> D;
        
        Func(Y, X, getDir(D));
        
        cin >> Y >> X;
        Map[Y][X] = 'S';
    }
    
    cout << score << "\n";
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cout << Map[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}







