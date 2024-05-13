#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int arr[1000][1000];

bool compare(int a, int b) {
    return a > b;
}

int main() {
    int r, c, n;
    cin >> r >> c >> n;

    int dummy;
    for (int i = 0; i < n; i++) {
        cin >> dummy;
        v.push_back(dummy);
    }

    sort(v.begin(), v.end(), compare);

    int num = 0;
    int x = 0;
    int y = 0;
    int index = 0;
    for (int i = 0; i < c; i++) {
        if (i < n) {
            arr[x][y] = v[index];
            num++;
            y++;
            index++;
        } else {
            cout << num;
            return 0;
        }
    }

    for (int i = 1; i < r; i++) { // 행
        for (int j = 0; j < c; j++) { // 열
            while (true) {
                if (index >= n) {
                    cout << num;
                    return 0;
                }
                if (v[index] < arr[i - 1][j]) {
                    arr[i][j] = v[index];
                    num++;
                    index++;
                    break;
                }
                index++;
            }
        }
    }

    cout << num;

    return 0;
}