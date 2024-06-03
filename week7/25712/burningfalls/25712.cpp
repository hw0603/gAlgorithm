#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(0); cout.tie(0);

bool Overlap(pair<int, int> a, pair<int, int> b) {
    if (a.second < b.first || b.second < a.first) {
        return false;
    }
    return true;
}

int main() {
    FASTIO;
    int N, M;
    cin >> N >> M;
    vector<int> len(M);
    vector<vector<int>> v(M, vector<int>(20));
    for(int i = 0; i < M; i++) {
        cin >> len[i];
    }
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < len[i]; j++) {
            cin >> v[i][j];
        }
    }
    
    vector<pair<int, int>> road, new_road;
    for(int j = 0; j < len[0]; j+=2) {
        road.push_back({v[0][j], v[0][j + 1]});
    }
    for(int i = 1; i < M; i++) {
        for(int j = 0; j < len[i]; j+=2) {
            pair<int, int> r = {v[i][j], v[i][j + 1]};
            bool flag = false;
            for(int k = 0; k < road.size(); k++) {
                flag |= Overlap(r, road[k]);
            }
            if (flag) {
                new_road.push_back(r);
            }
        }
        road = new_road;
        new_road.clear();
    }
    
    cout << (road.empty() ? "NO" : "YES") << "\n";
    
    return 0;
}

