#include <iostream>
#include <algorithm>

using namespace std;
int n;
int arr[101010];
int dp[101010];

int count(int num) {
	int res = 0;
	while (num) {
		res += num % 2;
		num >>= 1;
	}
	return res;
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];

	dp[1] = count(arr[0] ^ arr[1]);
	dp[2] = count(arr[0] ^ arr[1] ^ arr[2]);
	dp[3] = dp[1] + count(arr[2] ^ arr[3]);
	for (int i = 4; i < n; ++i) {
		int two = count(arr[i] ^ arr[i-1]);
		int three = count(arr[i] ^ arr[i-1] ^ arr[i-2]);
		dp[i] = max(dp[i-2] + two, dp[i-3] + three);
	}

	cout << dp[n-1];
}

