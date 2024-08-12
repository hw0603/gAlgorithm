#include <bits/stdc++.h>
using namespace std;
 
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

int main() {
    FASTIO;
    int N, K, Q, M;
    cin >> N >> K >> Q >> M;
    vector<int> check(N + 3, 0);
    for(int i = 0; i < K; i++) {
        int num;
        cin >> num;
        check[num] = -1;
    }
    for(int i = 0; i < Q; i++) {
        int num;
        cin >> num;
        if (check[num] == -1) continue;
        for(int j = num; j <= N + 2; j += num) {
            if (check[j] == -1) continue;
            check[j] = 1;
        }
    }
    
    vector<int> sum(N + 3, 0);
    for(int i = 3; i <= N + 2; i++) {
        sum[i] = sum[i - 1] + (check[i] == 1 ? 0 : 1);
    }
    
    for(int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        cout << sum[e] - sum[s - 1] << "\n";
    }
    
    
    return 0;
}
