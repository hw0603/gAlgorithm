#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll T, N, arr[101010];

void solve() {
	cin >> N;
	ll ans = 0;
	for (int i = 0; i < N; i++) cin >> arr[i];
	int l = 0, r = 1;
	while (l < N-1) {
		while (l < N-1 && arr[l] == arr[r]) l++, r++;
		while (r < N-1 && (arr[r] - arr[r-1]) * (arr[r+1] - arr[r]) < 0) r++;
		if (r < N) {
			ll len = (r - l + 1);
			ans += len * (len - 1) / 2;		
		}
		l = r, r++;
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> T;
	while (T--) solve();
	return 0;
}
