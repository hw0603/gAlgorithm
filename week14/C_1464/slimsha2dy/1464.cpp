#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;
string s;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s;

	deque<char> dq;
	for (char c : s) {
		if (dq.empty()) {
			dq.push_back(c);
			continue;
		}
		if (dq.front() >= c)
			dq.push_front(c);
		else
			dq.push_back(c);
	}
	for (char c : dq) {
		cout << c;
	}
}

