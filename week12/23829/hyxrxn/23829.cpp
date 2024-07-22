#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, q, x;
vector<int> tree;
long long sum[100001];
long long answer;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;
    int dummy;
    for (int i = 0; i < n; i++) {
        cin >> dummy;
        tree.push_back(dummy);
    }
    tree.push_back(0);
    tree.push_back(10000000);

    sort(tree.begin(), tree.end());
    sum[0] = tree[0];
    for (int i = 1; i < n + 2; i++) {
        sum[i] = sum[i - 1] + tree[i];
    }

    for (int i = 0; i < q; i++) {
        cin >> x;
        int lower = 0;
        int upper = n + 1;
        int location; // location 번째 나무와 location + 1 번째 나무 사이에 x가 있다
        while (true) {
            int middle = (lower + upper + 1) / 2;
            if (tree[middle] <= x && x <= tree[middle + 1]) {
                location = middle;
                break;
            } else if (x < tree[middle]) {
                upper = middle - 1;
            } else {
                lower = middle + 1;
            }
        }
        answer = sum[n + 1] - 2 * sum[location] + (location + 1 - (n + 2 - (location + 1))) * (long long)x;

        cout << answer - 10000000 << "\n";
    }

    return 0;
}

//    |t1 - x| + |t2 - x| + |t3 - x| + |t4 - x| + |t5 - x|
//
//    - t1 - t2 - t3 + t4 + t5 + 3x - 2x
//    - (t1 + t2 + t3) + (t4 + t5) + (3 - 2)x
// 처음부터...