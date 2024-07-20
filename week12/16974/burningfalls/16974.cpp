#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define ll long long
#define MAX 51

vector<ll> len(MAX), P(MAX);

ll Func(ll level, ll x) {
    if (level == 0) {
        return 1;
    }
    
    ll mid = len[level] / 2 + 1;
    if (x == 1) {
        return 0;
    } else if (1 < x && x < mid) {
        return Func(level - 1, x - 1);
    } else if (x == mid) {
        return P[level - 1] + 1;
    } else if (mid < x && x < len[level]) {
        return P[level - 1] + 1 + Func(level - 1, x - mid);
    } else if (x == len[level]) {
        return P[level];
    }
    return 0;
}

int main() {
    FASTIO;
    ll N, X;
    cin >> N >> X;
    len[0] = 1;
    P[0] = 1;
    for(int i = 1; i <= N; i++) {
        len[i] = 2 * len[i - 1] + 3;
        P[i] = 2 * P[i - 1] + 1;
    }
    
    cout << Func(N, X) << "\n";
    
    return 0;
}




