#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); ios_base::sync_with_stdio(0);

int main() {
    FASTIO;
    int num;
    cin >> num;
    
    set<pair<int, int>> ans;
    vector<int> t1 = {508, 108};
    vector<int> t2 = {212, 305};
    for(int i = 0; i <= 200; i++) {
        for(int j = 0; j <= 200; j++) {
            for(int m = 0; m < 2; m++) {
                for(int n = 0; n < 2; n++) {
                    if ((i * t1[m] + j * t2[n]) * 4763 == num) {
                        ans.insert({i, j});
                    }
                }
            }
        }
    }
    
    cout << ans.size() << "\n";
    for(pair<int, int> x : ans) {
        cout << x.first << " " << x.second << "\n";
    }
    
    return 0;
}






