#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); ios_base::sync_with_stdio(0);

int main() {
    FASTIO;
    int N;
    cin >> N;
    vector<int> S(N);
    for(int i = 0; i < N; i++) {
        cin >> S[i];
    }
    
    vector<int> cnt(10, 0);
    int kind = 0;
    int maxi = 0;
    int right = 0;
    for(int left = 0; left < N; left++) {
        while(right < N && !(kind == 2 && cnt[S[right]] == 0)) {
            if (cnt[S[right]] == 0) {
                kind++;
            }
            cnt[S[right]]++;
            right++;
        }
        maxi = max(maxi, right - left);
        
        if (cnt[S[left]] == 1) {
            kind--;
        }
        cnt[S[left]]--;
    }
    
    cout << maxi << "\n";
    
    return 0;
}







