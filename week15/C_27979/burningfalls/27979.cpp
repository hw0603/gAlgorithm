#include <bits/stdc++.h>
using namespace std;
 
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

int main() {
    FASTIO;
    int N;
    cin >> N;
    vector<int> W(N);
    for(int i = 0; i < N; i++) {
        cin >> W[i];
    }
    
    vector<int> tmp(W);
    sort(tmp.begin(), tmp.end());
    int idx = N - 1;
    int cnt = 0;
    for(int i = N - 1; i >= 0; i--) {
        if (W[i] == tmp[idx]) {
            cnt++;
            idx--;
        }
    }
    
    cout << N - cnt << "\n";
    
    return 0;
}

