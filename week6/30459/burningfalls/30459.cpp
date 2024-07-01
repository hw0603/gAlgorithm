#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
    FASTIO;
    int N, M, R;
    cin >> N >> M >> R;
    vector<int> A(N), B(M);
    FOR(i, 0, N - 1) {
        cin >> A[i];
    }
    FOR(i, 0, M - 1) {
        cin >> B[i];
    }
    
    set<int> sub;
    FOR(i, 0, N - 1) {
        FOR(j, i + 1, N - 1) {
            sub.insert(abs(A[i] - A[j]));
        }
    }
    vector<int> v;
    for(int x : sub) {
        v.push_back(x);
    }
    
    double maxi = -1;
    FOR(i, 0, M - 1) {
        int tmp = R * 2 / B[i];
        int ub = upper_bound(ALL(v), tmp) - v.begin();
        if (ub == 0) continue;
        double result = v[ub - 1];
        maxi = max(maxi, result * B[i] / 2);
    }
    cout << fixed << setprecision(1);
    if (maxi == -1) {
        cout << -1;
    }
    else {
        cout << maxi;
    }
    cout << "\n";
    
    return 0;
}

