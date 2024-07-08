#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MAX 1002

struct NODE {
    int u;
    int v;
    int d;
    
    bool operator< (const NODE &n) const {
        return d > n.d;
    }
};

int N, M;
vector<char> type(MAX);
vector<int> Parent(MAX);
priority_queue<NODE> pq;

int Find(int node) {
    if (Parent[node] == node) {
        return node;
    }
    return Parent[node] = Find(Parent[node]);
}

bool is_Same(int n1, int n2) {
    n1 = Find(n1);
    n2 = Find(n2);
    return n1 == n2;
}

void Union(int n1, int n2) {
    n1 = Find(n1);
    n2 = Find(n2);
    Parent[min(n1, n2)] = max(n1, n2);
}

int main() {
    FASTIO;
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        cin >> type[i];
    }
    for(int i = 1; i <= N; i++) {
        Parent[i] = i;
    }
    for(int i = 1; i <= M; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        if (type[u] == type[v]) continue;
        pq.push({u, v, d});
    }
    
    int ans = 0;
    int cnt = 0;
    while(!pq.empty()) {
        NODE n = pq.top();
        pq.pop();
        if (!is_Same(n.u, n.v)) {
            Union(n.u, n.v);
            ans += n.d;
            cnt++;
        }
    }
    
    cout << (cnt == N - 1 ? ans : -1) << "\n";

    return 0;
}
