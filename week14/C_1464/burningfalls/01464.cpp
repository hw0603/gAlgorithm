#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

int main() {
    FASTIO;
    string s;
    cin >> s;
    deque<char> dq;
    dq.push_back(s[0]);
    for(int i = 1; i < s.size(); i++) {
        if (s[i] <= dq.front()) {
            dq.push_front(s[i]);
        } else {
            dq.push_back(s[i]);
        }
    }
    
    for(int i = 0; i < s.size(); i++) {
        cout << dq[i];
    }
    cout << "\n";
    
    return 0;
}




