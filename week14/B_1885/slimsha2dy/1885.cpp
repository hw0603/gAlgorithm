#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int n, m;
int arr[101010], vis[10101];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	
	int res = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (vis[arr[i]]) continue;
		vis[arr[i]] = 1;
		cnt++;
		if (cnt == m) {
			res++;
			memset(vis, 0, sizeof(vis));
			cnt = 0;
		}
	}

	cout << res+1;
}

