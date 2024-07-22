#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
int n;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	stack<int> s;
	int res = 0;
	while (n--) {
		char c;
		cin >> c;
		if (c == '(') {
			s.push(0);
			continue;
		}
		if (s.empty()) continue;
		if (s.top() == -1) continue;
		int i;
		if (s.top() == 0) {
			s.pop();
			i = 2;
		}
		else if (s.top() > 0) {
			i = s.top(); s.pop();
			if (s.empty()) {
				s.push(-1);
				continue;
			}
			if (s.top() == -1) {
				s.push(-1);
				continue;
			}
			s.pop();
			i += 2;
		}
		while (!s.empty() && s.top() > 0) {
			i += s.top(); s.pop();
		}
		s.push(i);
		res = max(i, res);
	}
	cout << res;
}

