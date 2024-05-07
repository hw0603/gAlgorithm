#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); ios_base::sync_with_stdio(0);

int main() {
    FASTIO;
    int N, P;
    int W, L, G;
    cin >> N >> P;
    cin >> W >> L >> G;
    map<string, char> mp;
    for(int i = 0; i < P; i++) {
        string name;
        char kind;
        cin >> name >> kind;
        mp[name] = kind;
    }
    vector<string> name(N);
    for(int i = 0; i < N; i++) {
        cin >> name[i];
    }
    
    int score = 0;
    bool flag = false;
    for(int i = 0; i < N; i++) {
        if (mp.count(name[i]) && mp[name[i]] == 'W') {
            score += W;
        } else {
            score = max(0, score - L);
        }
        if (score >= G) {
            flag = true;
            break;
        }
    }
    
    cout << (flag ? "I AM NOT IRONMAN!!" : "I AM IRONMAN!!") << "\n";
    
    return 0;
}






