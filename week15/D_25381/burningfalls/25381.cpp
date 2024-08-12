#include <bits/stdc++.h>
using namespace std;
 
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

int main() {
    FASTIO;
    string s;
    cin >> s;
    int len = (int)s.size();
    vector<int> A, B, C;
    for(int i = 0; i < len; i++) {
        if (s[i] == 'A') {
            A.push_back(i);
        } else if (s[i] == 'B') {
            B.push_back(i);
        } else if (s[i] == 'C') {
            C.push_back(i);
        }
    }
    
    int aidx = 0, bidx = 0, cidx = 0;
    int cnt = 0;
    while(bidx < B.size() && cidx < C.size()) {
        if (B[bidx] < C[cidx]) {
            cnt++;
            bidx++;
            cidx++;
        } else {
            cidx++;
        }
    }
    
    while(aidx < A.size() && bidx < B.size()) {
        if (A[aidx] < B[bidx]) {
            cnt++;
            aidx++;
            bidx++;
        } else {
            bidx++;
        }
    }
    
    cout << cnt << "\n";
    
    return 0;
}
