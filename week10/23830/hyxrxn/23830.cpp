#include <iostream>
using namespace std;

int n, p, q, r;
long long s;
int arr[100001];
int score;
long long sum;

bool able(int k) {
    sum = 0;
    for (int i = 0; i < n; i++) {
        score = arr[i];
        sum += score;
        if (score > k + r) {
            sum -= p;
        } else if (score < k) {
            sum += q;
        }
    }
    return sum >= s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> p >> q >> r >> s;

    int answer = 1000000;
    int lower = 1;
    int upper = 100001;
    int middle;
    while (lower <= upper) {
        middle = (lower + upper + 1) / 2;
        if (able(middle)) {
            answer = middle;
            upper = middle - 1;
        } else {
            lower = middle + 1;
        }
    }

    if (answer == 1000000) {
        cout << -1;
        return 0;
    }
    cout << answer;
    return 0;
}
