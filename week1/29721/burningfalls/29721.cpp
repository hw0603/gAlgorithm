#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> v(K);
    set<pair<int, int>> se;
    for(int i = 0; i < K; i++) {
        cin >> v[i].first >> v[i].second;
        se.insert(v[i]);
    }
    
    vector<int> dy = {-2, 2, 0, 0};
    vector<int> dx = {0, 0, -2, 2};
    for(int i = 0; i < K; i++) {
        for(int j = 0; j < 4; j++) {
            int nx = v[i].first + dx[j];
            int ny = v[i].second + dy[j];
            if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
            se.insert({nx, ny});
        }
    }
    
    cout << se.size() - K << "\n";
    
    return 0;
}




