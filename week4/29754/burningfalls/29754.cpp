#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); ios_base::sync_with_stdio(0);

struct NODE {
    string name;
    string st;
    string et;
};

int Calc(string st, string et) {
    int a = ((st[0] - '0') * 10 + (st[1] - '0')) * 60 + ((st[3] - '0') * 10 + (st[4] - '0'));
    int b = ((et[0] - '0') * 10 + (et[1] - '0')) * 60 + ((et[3] - '0') * 10 + (et[4] - '0'));
    return b - a;
}

int main() {
    FASTIO;
    int N, M;
    cin >> N >> M;
    vector<vector<NODE>> v(M + 1, vector<NODE>());
    for(int i = 0; i < N; i++) {
        string name, st, et;
        int day;
        cin >> name >> day >> st >> et;
        v[day].push_back({name, st, et});
    }
    
    map<string, int> mp;
    map<string, pair<int, int>> tmp;
    for(int i = 1; i <= M; i++) {
        for(int j = 0; j < v[i].size(); j++) {
            string name = v[i][j].name;
            string st = v[i][j].st;
            string et = v[i][j].et;
            tmp[name].first += 1;
            tmp[name].second += Calc(st, et);
        }
        
        if (i % 7 == 0) {
            for(auto &x : tmp) {
                if (x.second.first >= 5 && x.second.second >= 3600) {
                    mp[x.first] += 1;
                }
            }
            tmp.clear();
        }
    }
    
    vector<string> ans;
    for(auto &x : mp) {
        if (x.second == M / 7) {
            ans.push_back(x.first);
        }
    }
    
    sort(ans.begin(), ans.end());
    if (ans.empty()) {
        cout << -1 << "\n";
        return 0;
    }
    
    for(string name : ans) {
        cout << name << "\n";
    }
    cout << "\n";
    
    return 0;
}





