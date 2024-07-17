#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

int main() {
    FASTIO;
    vector<vector<char>> v(31, vector<char>(101, '0'));
    for(int i = 1; i <= 5; i++) {
        v[i][45] = '1';
        v[i][55] = '1';
    }
    for(int i = 40; i <= 60; i++) {
        v[6][i] = '1';
    }
    
    for(int k = 1; k <= 4; k++) {
        for(int i = 50 - 10 * k; i <= 10 * k + 50; i++) {
            v[5 * k + 1][i] = '1';
        }
        for(int i = 5 * k + 1; i <= 5 * k + 5; i++) {
            v[i][50 - 10 * k] = '1';
            v[i][50 + 10 * k] = '1';
        }
        for(int i = 50 - 10 * k; i <= 10 * k + 50; i++) {
            v[5 * k + 5][i] = '1';
        }
    }
    
    
    for(int i = 1; i <= 30; i++) {
        for(int j = 1; j <= 100; j++) {
            if (v[i][j] == '1') {
                cout << "*";
            } else if (v[i][j] == '0') {
                cout << " ";
            }
        }
        cout << "\n";
    }
    
    return 0;
}


