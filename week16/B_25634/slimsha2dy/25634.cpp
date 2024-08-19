#include <iostream>
#include <algorithm>

using namespace std;
int n, arr[202020], jg[202020], dp[202020];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	int st = -1;
	int en = -1;
	int total = 0;
	for (int i = 0; i < n; ++i) {
		cin >> jg[i];
		if (jg[i] == 0 && st == -1) st = i;
		if (jg[i] == 0) en = i;
		total += arr[i] * jg[i];
	}

	if (st == -1) {
		cout << total - *min_element(arr, arr+n);
		return 0;
	}

	dp[st] = arr[st];
	int maxi = dp[st];
	for (int i = st+1; i <= en; ++i) {
		int tmp = arr[i] * (jg[i] ? -1 : 1);
		dp[i] = max(dp[i-1], 0) + tmp;
		maxi = max(dp[i], maxi);
	}

	cout << total + maxi;
}

