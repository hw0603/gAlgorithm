#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n, arr[303030], vis[303030];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<int> t[n+1];
	for (int i = 2; i <= n; ++i) {
		int input;
		cin >> input;
		t[input].push_back(i);
	}
	for (int i = 1; i <= n; ++i) cin >> arr[i];

	priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
	pq.push({arr[1], 1});
	int res = 0;
	while (!pq.empty()) {
		pair<int, int> tmp = pq.top(); pq.pop();
		res += tmp.first;
		for (int adj : t[tmp.second]) {
			pq.push({arr[adj], adj});
		}
		cout << res << '\n';
	}
}

