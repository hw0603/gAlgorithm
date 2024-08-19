#include <iostream>
#include <algorithm>

using namespace std;
int t, n, arr[1010];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> t;
	while (t--) {
		cin >> n;
		int res = 0;
		for (int i = 0; i < n; ++i) cin >> arr[i];
		for (int i = 0; i < n; ++i) {
			for (int j = 1; j < n - i; ++j) {
				if (arr[j-1] > arr[j]) {
					swap(arr[j-1], arr[j]);
					res++;
				}
			}
		}
		cout << res << '\n';
	}
}

