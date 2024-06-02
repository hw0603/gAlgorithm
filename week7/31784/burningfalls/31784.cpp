#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<char> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    for(int i = 0; i < N - 1; i++) {
        if (v[i] == 'A') continue;
        int tmp = ('Z' - v[i]) + 1;
        if (tmp <= K) {
            v[i] = 'A';
            K -= tmp;
        }
    }
    v[N - 1] = ((v[N - 1] - 'A') + K) % 26 + 'A';
    
    for(int i = 0; i < N; i++) {
        cout << v[i];
    }
    cout << "\n";
    
    return 0;
}

