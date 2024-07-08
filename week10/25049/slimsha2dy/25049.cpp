#include <iostream>
#include <algorithm>

using namespace std;
int n;
int arr[505050];
long long acm[505050];
long long ldp[505050], ldp2[505050], rdp[505050];

int	main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		acm[i] = acm[i-1] + arr[i];
	}

	// ldp[k]: k까지 봤을 때 acm의 최솟값
	// rdp[k]: n ~ n-k까지 봤을 때 acm의 최댓값
	// ldp2[k]: k까지 봤을 때 부분합의 최댓값
	rdp[n+1] = -2147483648;
	for (int i = 1; i <= n; ++i) {
		ldp[i] = min(ldp[i-1], acm[i]);
		ldp2[i] = max(ldp2[i-1], acm[i] - ldp[i]);
		rdp[n+1-i] = max(rdp[n+1-i+1], acm[n+1-i]);
	}
	rdp[0] = max(rdp[1], acm[0]);
	long long res = rdp[0] - acm[0];
	for (int i = 1; i <= n; ++i) {
		res = max(ldp2[i] + rdp[i] - acm[i], res);
	}

	for (int i = 0; i <= n; ++i) cout << acm[i] << ' ';
	cout << '\n';
	for (int i = 0; i <= n; ++i) cout << ldp[i] << ' ';
	cout << '\n';
	for (int i = 0; i <= n; ++i) cout << rdp[i] << ' ';
	cout << '\n';
	for (int i = 0; i <= n; ++i) cout << ldp2[i] << ' ';
	cout << '\n';

	cout << res << ' ' <<  acm[n];
}

