#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
long long l, n, k;
int d[2] = {-1, 1};

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> l >> n >> k;
	queue<pair<long long, long long>> q;
	set<long long> s;
	for (int i = 0; i < n; ++i)  {
		long long input;
		cin >> input;
		q.push({input, 0});
		s.insert(input);
	}

	while (k--) {
		pair<long long, long long> tmp = q.front(); q.pop();
		cout << tmp.second << '\n';
		for (int i = 0; i < 2; ++i) {
			long long nxt = tmp.first + d[i];
			if (nxt < 0 || nxt > l) continue;
			if (s.count(nxt)) continue;
			q.push({nxt, tmp.second+1});
			s.insert(nxt);
		}
	}
}

