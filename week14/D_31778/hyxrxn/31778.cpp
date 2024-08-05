#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
char arr[200001];
vector<int> pLocation;
vector<int> cLocation;
long long answer = 0;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        if (arr[i] == 'C') {
            cLocation.push_back(i);
        }
        if (arr[n + 1 - i] == 'P') {
            pLocation.push_back(n + 1 - i);
        }
    }

    int num = 0;
    k = min(k, (int)pLocation.size());
    k = min(k, (int)cLocation.size());
    while (num < k && pLocation[num] > cLocation[num]) {
        arr[pLocation[num]] = 'C';
        arr[cLocation[num]] = 'P';
        num++;
    }

    int pNum = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] == 'P') {
            pNum++;
        } else {
            answer += pNum * (pNum - 1) / 2;
        }
    }

    cout << answer;
    return 0;
}
