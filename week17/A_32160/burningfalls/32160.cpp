#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); ios_base::sync_with_stdio(0);

int main() {
    FASTIO;
    int N;
    cin >> N;
    
    if ((N / 2) % 2 == 0) {
        cout << N;
    } else {
        cout << N - 1;
    }
    cout << "\n";
    
    int num = N - 1;
    for(int i = N - 2; i >= 1; i--) {
        cout << i << " " << num << "\n";
        num = abs(i - num);
    }
    cout << N << " " << num << "\n";
    
    return 0;
}









