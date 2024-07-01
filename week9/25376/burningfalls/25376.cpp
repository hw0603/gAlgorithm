#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(0); cout.tie(0);

int N;
vector<int> v(20, 0);
vector<int> visited(1 << 20, -1);

void BFS(int start) {
    queue<int> q;
    visited[start] = 0;
    q.push(start);
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < N; i++) {
            if (cur & (1 << i)) continue;
            int next = cur ^ v[i];
            next |= (1 << i);
            if (visited[next] != -1) continue;
            visited[next] = visited[cur] + 1;
            q.push(next);
        }
    }
}

int main() {
    FASTIO;
    int A, B, C;
    cin >> N;
    int start = 0;
    for(int i = 0; i < N; i++) {
        cin >> A;
        start |= (1 << i) * A;
    }
    for(int i = 0; i < N; i++) {
        cin >> C;
        for(int j = 0; j < C; j++) {
            cin >> B;
            v[i] |= (1 << (B - 1));
        }
    }
    
    BFS(start);
    
    cout << visited[(1 << N) - 1] << "\n";
    
    return 0;
}



