#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
long long cnum[202020];
long long pnum[202020];
string s;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	cin >> s;
	int st = 0;
	int en = n-1;
	while (m) {
		while (s[st] == 'P') st++;
		while (s[en] == 'C') en--;
		if (st >= en) break;
		s[st] = 'P';
		s[en] = 'C';
		m--;
	}

	for (int i = n-1; i >= 0; --i) {
		if (s[i] == 'C') cnum[i] = cnum[i+1] + 1;
		else cnum[i] = cnum[i+1];
	}
	if (s[0] == 'P') pnum[0] = 1;
	for (int i = 1; i < n; ++i) {
		if (s[i] == 'P') pnum[i] = pnum[i-1] + 1;
		else pnum[i] = pnum[i-1];
	}

	long long ans = 0;
	for (int i = 1; i < n-1; ++i) {
		if (s[i] == 'C') continue;
		long long tmp = pnum[i-1] * cnum[i+1];
		ans += tmp;
	}
	cout << ans;
}

