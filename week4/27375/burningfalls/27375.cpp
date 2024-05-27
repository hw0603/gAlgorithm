#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); ios_base::sync_with_stdio(0);

struct NODE {
    int w;
    int s;
    int e;
};

int main() {
    FASTIO;
    int N, K;
    cin >> N >> K;
    vector<NODE> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i].w >> v[i].s >> v[i].e;
    }
    
    int ans = 0;
    for(int i = 0; i < (1 << N); i++) {
        int fri_cnt = 0;
        int score = 0;
        vector<vector<pair<int, int>>> tmp(6, vector<pair<int, int>>());
        for(int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                fri_cnt += (v[j].w == 5);
                score += (v[j].e - v[j].s + 1);
                tmp[v[j].w].push_back({v[j].s, v[j].e});
            }
        }
        if (fri_cnt > 0) continue;
        if (score != K) continue;
        
        for(int j = 1; j <= 5; j++) {
            sort(tmp[j].begin(), tmp[j].end());
        }
        bool flag = true;
        for(int j = 1; j <= 5; j++) {
            int right = 0;
            for(int k = 0; k < tmp[j].size(); k++) {
                if (right >= tmp[j][k].first) {
                    flag = false;
                    break;
                }
                right = tmp[j][k].second;
            }
        }
        if (!flag) continue;
        
        ans++;
    }
    
    cout << ans << "\n";
    
    return 0;
}





