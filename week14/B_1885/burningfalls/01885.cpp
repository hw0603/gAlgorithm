#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

int main() {
    FASTIO;
    int N, K;
    cin >> N >> K;
    vector<int> v(N);
    set<int> se;
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        se.insert(v[i]);
        if (se.size() == K) {
            cnt++;
            se.clear();
        }
    }
    
    cout << cnt + 1 << "\n";
    
    return 0;
}




