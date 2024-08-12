#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
int n, m;
int arr[202020];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) cin >> arr[i];

	int maxi = 0;
	int cnt = 0;
	stack<int> s;
	s.push(arr[n-1]);
	for (int i = n-2; i >= 0; --i) {
		while (!s.empty() && arr[i] > s.top()) {
			maxi = max(maxi, s.top());
			s.pop();
			cnt++;
		}
		s.push(arr[i]);
	}
	while (!s.empty() && maxi > s.top()) {
		s.pop();
		cnt++;
	}

	cout << cnt;
}

