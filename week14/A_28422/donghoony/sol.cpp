#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 0x3f3f3f3f;
typedef long long ll;

ll N, arr[101010], d[101010];

ll f(int x) {
    if (x > N || N == 1) return 0;
    ll& ret = d[x];
    if (ret != -1) return ret;
    ret = -INF;
   
    if (x <= N-2)
        ret = max(ret, f(x+3) + __builtin_popcount(arr[x] ^ arr[x+1] ^ arr[x+2]));
    if (x <= N-1)
        ret = max(ret, f(x+2) + __builtin_popcount(arr[x] ^ arr[x+1]));
    return ret;
}

int main(){
    memset(d, -1, sizeof d);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    cout << f(1) << endl;
}
