#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

int main() {
    FASTIO;
    int N, M, X, Y;
    cin >> N >> M;
    vector<int> v(N + 1, 0);
    for(int i = 0; i < M; i++) {
        int num;
        cin >> num;
        v[num] = 1;
    }
    cin >> X >> Y;
    
    int left = 1, right = X;
    int sum = 0;
    for(int i = 1; i <= X; i++) {
        sum += v[i];
    }
    
    int mini = sum;
    while(right < N) {
        right++;
        sum += v[right];
        sum -= v[left];
        left++;
        mini = min(mini, sum);
    }
    
    cout << M - max(mini, Y) << "\n";
    
    return 0;
}


