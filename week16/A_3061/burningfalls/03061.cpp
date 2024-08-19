#include <bits/stdc++.h>
using namespace std;
 
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

int main() {
    FASTIO;
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        vector<int> index(N + 1);
        for(int i = 1; i <= N; i++) {
            int num;
            cin >> num;
            index[num] = i;
        }
        
        int ans = 0;
        for(int i = 1; i <= N; i++) {
            for(int j = i + 1; j <= N; j++) {
                if (index[j] < index[i]) {
                    index[j] += 1;
                }
            }
            ans += index[i] - i;
        }
        cout << ans << "\n";
    }
    
    return 0;
}


