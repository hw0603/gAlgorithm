#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
long long arr[101010], ldp[101010], rdp[101010];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> arr[i];

	sort(arr, arr+n);
	rdp[n-1] = arr[n-1] - arr[0];
	ldp[0] = arr[n-1] - arr[0];
	for (int i = 1; i < n; ++i) {
		rdp[n-i-1] = rdp[n-i] + arr[n-i-1] - arr[0];
		ldp[i] = ldp[i-1] + arr[n-1] - arr[i];
	}

	while (m--) {
		long long tmp;
		cin >> tmp;
		long long left = lower_bound(arr, arr+n, tmp) - arr;
		long long right = upper_bound(arr, arr+n, tmp) - arr;

		long long res = 0;
		if (left != 0) res += ldp[left-1] - left*(arr[n-1]-tmp);
		res += rdp[right] - (n-right) * (tmp-arr[0]);
		cout << res << '\n';
	}
}

