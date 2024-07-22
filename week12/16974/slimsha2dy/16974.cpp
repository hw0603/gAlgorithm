#include <iostream>

using namespace std;
long long n, m, ans;
long long dp[52], len[52];

void recur(int dep) {
	if (dep == 0) {
		m--;
		ans++;
		return;
	}
	m--;
	if(!m) return;
	if (len[dep-1] <= m) {
		ans += dp[dep-1];
		m -= len[dep-1];
	}
	else recur(dep-1);
	if (!m) return;
	m--;
	ans++;
	if (!m) return;
	if (len[dep-1] <= m) {
		ans += dp[dep-1];
		m -= len[dep-1];
	}
	else recur(dep-1);
	if (!m) return;
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	dp[0] = 1;
	len[0] = 1;
	for (int i = 1; i <= n; ++i) {
		dp[i] = dp[i-1] * 2 + 1;
		len[i] = len[i-1] * 2 + 3;
	}
	recur(n);
	cout << ans;
}

