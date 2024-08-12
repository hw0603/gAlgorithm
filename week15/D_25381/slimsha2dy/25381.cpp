#include <iostream>
#include <algorithm>

using namespace std;
string s;
int res;
bool vis[303030];

void func(char a, char b) {
	int size = s.size();
	int tmp = 0;
	for (int i = 0; i < size; ++i) {
		if (s[i] != a || vis[i]) continue;
		if (tmp <= i) tmp = i+1;
		while (tmp < size && (vis[tmp] || s[tmp] != b)) tmp++;
		if (tmp >= size) break;
		vis[i] = 1; vis[tmp++] = 1;
		res++;
	}
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s;
	int size = s.size();
	func('B', 'C');
	func('A', 'B');
	cout << res;
}

