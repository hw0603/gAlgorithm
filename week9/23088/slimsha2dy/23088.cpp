#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int n;
tuple<int, int, int> arr[300002];

struct cmp {
  bool operator()(tuple<int, int, int> &a, tuple<int, int, int> &b) {
    int anum, arank, arun, bnum, brank, brun;
    if (get<1>(a) == get<1>(b)) {
      if (get<2>(a) == get<2>(b))
        return get<0>(a) > get<0>(b);
      return get<2>(a) > get<2>(b);
    }
    return get<1>(a) < get<1>(b);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int t, p, b;
    cin >> t >> p >> b;
    arr[i] = {t, p, b};
  }

  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, cmp> pq;
  int tmp = 0;
  for (int i = 1; i <= n; ++i) {
    int t, p, b;
    tie(t, p, b) = arr[i];
    while (!pq.empty() && tmp < t) {
      int num, rank, run;
      tie(num, rank, run) = pq.top(); pq.pop();
      cout << num << ' ';
      tmp += run;
    }
    if (tmp < t) tmp = t;
    pq.push({i, p-t, b});
  }

  while (!pq.empty()) {
    int num, rank, run;
    tie(num, rank, run) = pq.top(); pq.pop();
    cout << num << ' ';
  }
}
