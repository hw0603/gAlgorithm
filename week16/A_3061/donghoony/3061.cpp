#include <bits/stdc++.h>
using namespace std;

int a[1000], s[1000], N, ans;

void f(int l, int r){
    if (l > r) return;
    if (l == r){
        s[l] = a[l];
        return;
    }
    int m = (l + r) / 2;
    f(l, m); f(m+1, r);
    int i = l, j = m+1, k = l;
    while(i <= m && j <= r){
        if (a[i] < a[j]) s[k++] = a[i++];
        else s[k++] = a[j++], ans += m - i + 1;
    }
    while(i <= m) s[k++] = a[i++];
    while(j <= r) s[k++] = a[j++];
    for(int i = l; i <= r; i++) a[i] = s[i];
}

void solve() {
    cin >> N;
    ans = 0;
    for(int i = 0; i < N; i++) cin >> a[i];
    f(0, N-1);
    cout << ans << '\n';
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
