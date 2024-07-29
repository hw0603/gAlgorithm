#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int n, q, k;
vector<pair<int, int>> command;
int num, p;
int last = 0;
deque<int> result;
bool front = true;

int main() {
    cin >> n >> q >> k;
    for (int i = 0; i < q; i++) {
        cin >> num;
        if (num == 0) {
            cin >> p;
        } else if (num == 1) {
            last = i;
        }
        command.push_back({num, p});
    }

    for (int i = 0; i < last; i++) {
        if (command[i].first == 0) {
            result.push_back(command[i].second);
        }
    }
    sort(result.begin(), result.end());

    for (int i = last; i < q; i++) {
        if (command[i].first == 2) {
            front = !front;
        } else if (command[i].first == 0) {
            if (front) {
                result.push_front(command[i].second);
            } else {
                result.push_back(command[i].second);
            }
        }
    }

    if (front) {
        cout << result[k - 1];
    } else {
        cout << result[result.size() - k];
    }

    return 0;
}