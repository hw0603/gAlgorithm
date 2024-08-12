#include <bits/stdc++.h>
using namespace std;
 
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define ll long long
#define MAX 300001

ll L, N, K;
queue<ll> q;
map<ll, ll> visited;
vector<ll> ans;

void BFS() {
    while(!q.empty()) {
        ll n = q.front();
        q.pop();
        ans.push_back(visited[n]);
        if (ans.size() == K) {
            return;
        }
        if (n - 1 >= 0 && !visited.count(n - 1)) {
            visited[n - 1] = visited[n] + 1;
            q.push(n - 1);
        }
        if (n + 1 <= L && !visited.count(n + 1)) {
            visited[n + 1] = visited[n] + 1;
            q.push(n + 1);
        }
    }
}

int main() {
    FASTIO;
    cin >> L >> N >> K;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        q.push(A[i]);
        visited[A[i]] = 0;
    }
    
    BFS();
    
    for(int i = 0; i < K; i++) {
        cout << ans[i] << "\n";
    }
    
    return 0;
}


