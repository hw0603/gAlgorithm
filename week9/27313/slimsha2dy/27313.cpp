#include <iostream>
#include <algorithm>

using namespace std;
int n, m, k;
int arr[100002];
pair<long long, long long> dp[200004];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr+n);

  // dp[i]: i를 끝으로 최대한 묶었을 때 걸리는 시간이랑 본 애니 갯수
	long long res = 0;
	for (int i = 0; i < n; ++i) {
		if (i < k) dp[i] = {arr[i], i+1};
		else dp[i] = {dp[i-k].first + arr[i], dp[i-k].second + k};
		if (dp[i].first <= m) res = max(res, dp[i].second);
	}
	cout << res;
}
