#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr int INF = 0x3f3f3f3f;

ll N, M, v[323232], NM4, ans;
char arr[202][202];
vector<int> g[323232];

void dfs(int cur) {
    v[cur] = 1;
    for (auto nxt: g[cur]) {
        if (v[nxt]) continue;
        dfs(nxt);
    }
}

void merge(int a, int b) {
    g[a].push_back(b);
    g[b].push_back(a);
}

void merge_block(int y, int x, char type) {
    int pi = 4 * (y - 1) * M + 4 * (x - 1) + 1;
    if (type == 'O') {
        for (int i = 0; i < 4; i++) merge(pi + i, pi + i + NM4);
    } else if (type == 'I') {
        merge(pi, pi + 2), merge(pi + 1, pi + 3);
        merge(pi + NM4, pi + 2 + NM4), merge(pi + 1 + NM4, pi + 3 + NM4);
    } else {
        merge(pi, pi + 1), merge(pi + 2, pi + 3);
        merge(pi + NM4, pi + 1 + NM4), merge(pi + 2 + NM4, pi + 3 + NM4);
    }
}

int main() {
    cin >> N >> M;
    NM4 = 4 * N * M;
    for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) cin >> arr[i][j];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            merge_block(i, j, arr[i][j]);
            // right
            int pi = 4 * (i - 1) * M + 4 * (j - 1) + 1;
            if (j != M) {
                merge(pi + 1, pi + 4);
                merge(pi + 3, pi + 6);
                merge(pi + 1 + NM4, pi + 4 + NM4);
                merge(pi + 3 + NM4, pi + 6 + NM4);
            }
            // down
            if (i != N) {
                merge(pi + 2, pi + 2 + 4 * M - 2);
                merge(pi + 3, pi + 3 + 4 * M - 2);
                merge(pi + 2 + NM4, pi + 2 + 4 * M - 2 + NM4);
                merge(pi + 3 + NM4, pi + 3 + 4 * M - 2 + NM4);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int pi = 4 * (i - 1) * M + 4 * (j - 1) + 1;
            for (int k = 0; k < 4; k++) {
                if (!v[pi + k]) dfs(pi + k), ans++;
                if (!v[pi + k + NM4]) dfs(pi + k + NM4), ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
