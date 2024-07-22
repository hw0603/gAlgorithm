#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

int main() {
    FASTIO;
    int N;
    cin >> N;
    vector<char> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    int maxi = 0;
    vector<int> t;
    int left_cnt = 0, right_cnt = 0;
    for(int i = 0; i < N; i++) {
        if (v[i] == '(') {
            left_cnt++;
            t.push_back(0);
        } else if (v[i] == ')') {
            right_cnt++;
            if (left_cnt < right_cnt) {
                t.clear();
                left_cnt = 0;
                right_cnt = 0;
                continue;
            }
            int sum = 2;
            while(!t.empty() && t.back() != 0) {
                sum += t.back();
                t.pop_back();
            }
            t.pop_back();
            t.push_back(sum);
            maxi = max(maxi, sum);
        }
        
        int sum = 0;
        while(!t.empty() && t.back() != 0) {
            sum += t.back();
            t.pop_back();
        }
        if (sum != 0) {
            t.push_back(sum);
            maxi = max(maxi, sum);
        }
    }
    
    
    cout << maxi << "\n";
    
    return 0;
}




