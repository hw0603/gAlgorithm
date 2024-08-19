#include <bits/stdc++.h>
using namespace std;
 
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define ll long long
#define MAX 300001

int N;
vector<ll> A(MAX);
vector<vector<ll>> Edge(MAX, vector<ll>());
priority_queue<pair<ll, ll>> pq;
vector<ll> ans;

void Func() {
    while(!pq.empty()) {
        ll p = pq.top().first;
        ll cur = pq.top().second;
        pq.pop();
        ans.push_back(ans.back() + p);
        
        for(int i = 0; i < Edge[cur].size(); i++) {
            ll next = Edge[cur][i];
            pq.push({A[next], next});
        }
    }
}

int main() {
    FASTIO;
    cin >> N;
    for(int i = 2; i <= N; i++) {
        ll P;
        cin >> P;
        Edge[P].push_back(i);
    }
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    ans.push_back(0);
    
    pq.push({A[1], 1});
    Func();
    
    for(int i = 1; i <= N; i++) {
        cout << ans[i] << "\n";
    }
    
    return 0;
}


