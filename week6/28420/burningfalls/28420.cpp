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

int N, M;
vector<vector<int>> Map, Sum;

int Calculate(int a, int b, int c, int d) {
    return Sum[c][d] - Sum[c][b - 1] - Sum[a - 1][d] + Sum[a - 1][b - 1];
}

int main() {
    FASTIO;
    int a, b, c;
    cin >> N >> M;
    cin >> a >> b >> c;
    Map = vector<vector<int>>(N + 1, vector<int>(M + 1));
    Sum = vector<vector<int>>(N + 1, vector<int>(M + 1, 0));
    FOR(i, 1, N) {
        FOR(j, 1, M) {
            cin >> Map[i][j];
        }
    }
    FOR(i, 1, N) {
        FOR(j, 1, M) {
            Sum[i][j] = Sum[i][j - 1] + Sum[i - 1][j] - Sum[i - 1][j - 1] + Map[i][j];
        }
    }
    
    int mini = INF;
    FOR(i, 1, N - a + 1) {
        FOR(j, 1, M - (b + c) + 1) {
            int sum = Calculate(i, j, i + a - 1, j + b + c - 1);
            mini = min(mini, sum);
        }
    }
    FOR(i, 1, N - (a + b) + 1) {
        FOR(j, 1, M - (a + c) + 1) {
            int sum1 = Calculate(i, j, i + a - 1, j + c - 1);
            int sum2 = Calculate(i + a, j + c, i + a + b - 1, j + a + c - 1);
            mini = min(mini, sum1 + sum2);
        }
    }
    FOR(i, 1, N - (a + c) + 1) {
        FOR(j, 1, M - (a + b) + 1) {
            int sum1 = Calculate(i, j, i + a - 1, j + b - 1);
            int sum2 = Calculate(i + a, j + b, i + a + c - 1, j + a + b - 1);
            mini = min(mini, sum1 + sum2);
        }
    }
    cout << mini << "\n";
    
    return 0;
}

