#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(0); cout.tie(0);

struct TMP {
    int idx;
    int t;
    int p;
    int b;
    
    bool operator<(const TMP &n) const {
        if (t == n.t) {
            if (p == n.p) {
                if (b == n.b) {
                    return idx > n.idx;
                }
                return b > n.b;
            }
            return p < n.p;
        }
        return t > n.t;
    }
};

struct NODE {
    int idx;
    int t;
    int p;
    int b;
    
    bool operator<(const NODE &n) const {
        if (p == n.p) {
            if (b == n.b) {
                return idx > n.idx;
            }
            return b > n.b;
        }
        return p < n.p;
    }
};

NODE Change(TMP n) {
    return {n.idx, n.t, n.p, n.b};
}

int main() {
    FASTIO;
    int N;
    cin >> N;
    priority_queue<TMP> q;
    for(int i = 1; i <= N; i++) {
        int t, p, b;
        cin >> t >> p >> b;
        q.push({i, t, p, b});
    }
    
    vector<int> ans;
    priority_queue<NODE> pq;
    int time = 0;
    while(!pq.empty() || !q.empty()) {
        if (pq.empty()) {
            NODE n = Change(q.top());
            n.p -= n.t;
            pq.push(n);
            q.pop();
        }
        NODE n = pq.top();
        pq.pop();
        time = max(time, n.t) + n.b;
        ans.push_back(n.idx);
        
        while(!q.empty() && q.top().t <= time) {
            NODE n = Change(q.top());
            q.pop();
            n.p -= n.t;
            pq.push(n);
        }
    }
    
    for(int x : ans) {
        cout << x << " ";
    }
    cout << "\n";
    
    return 0;
}






