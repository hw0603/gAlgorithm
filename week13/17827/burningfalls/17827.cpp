#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

int main() {
    FASTIO;
    int N, M, V;
    cin >> N >> M >> V;
    vector<int> C(N);
    for(int i = 0; i < N; i++) {
        cin >> C[i];
    }
    V -= 1;
    
    for(int i = 0; i < M; i++) {
        int K;
        cin >> K;
        if (K < V) {
            cout << C[K];
        } else if (K >= V) {
            cout << C[V + (K - V) % (N - V)];
        }
        cout << "\n";
    }
    
    return 0;
}




