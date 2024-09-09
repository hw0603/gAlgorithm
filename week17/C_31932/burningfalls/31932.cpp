#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); ios_base::sync_with_stdio(0);
#define ll long long
#define LINF 1e18
#define MAX 100001

struct NODE1 {
    ll n;
    ll d;
    ll t;
};

struct NODE2 {
    ll n;
    ll d;
    
    bool operator<(const NODE2& node) const {
        return d > node.d;
    }
};

int N, M;
vector<vector<NODE1>> Edge(MAX, vector<NODE1>());
vector<ll> dist(MAX, LINF);
priority_queue<NODE2> pq;

void DT(ll snode, ll stime) {
    dist[snode] = stime;
    pq.push({snode, dist[snode]});
    while(!pq.empty()) {
        NODE2 cur = pq.top();
        pq.pop();
        if (cur.d > dist[cur.n]) continue;
        for(int i = 0; i < Edge[cur.n].size(); i++) {
            ll next = Edge[cur.n][i].n;
            ll ndist = cur.d + Edge[cur.n][i].d;
            if (ndist > Edge[cur.n][i].t) continue;
            if (dist[next] > ndist) {
                dist[next] = ndist;
                pq.push({next, dist[next]});
            }
        }
    }
}

int main() {
    FASTIO;
    cin >> N >> M;
    for(int i = 1; i <= M; i++) {
        ll u, v, d, t;
        cin >> u >> v >> d >> t;
        Edge[u].push_back({v, d, t});
        Edge[v].push_back({u, d, t});
    }
    
    ll left = 0, right = LINF;
    ll ans = -1;
    while(left <= right) {
        ll mid = (left + right) / 2;
        for(int i = 1; i <= N; i++) {
            dist[i] = LINF;
        }
        DT(1, mid);
        
        if (dist[N] != LINF) {
            ans = mid;
            left = mid + 1;
        } else if (dist[N] == LINF) {
            right = mid - 1;
        }
    }
    cout << ans << "\n";
    
    return 0;
}









