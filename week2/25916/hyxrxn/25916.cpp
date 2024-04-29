#include <iostream>
#include <algorithm>
using namespace std;

int arr[500002];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int left = 0;
    int right = 0;
    int max = 0;
    int present = 0;

    while(right < n) {
        if (arr[right] > m) { // 새로 막는 애가 전체 부피 초과라면
            while(right < n && arr[right] > m) { // 전체 부피보다 작거나 같아질 때까지 옆으로 이동
                left = right + 1;
                right = left;
            }
            if (right < n) { // 이동했는데 구멍 범위 안이면 갱신
                present = 0;
            }
            else { // 마지막 구멍까지 전체 부피 이상이면 거기서 끝
                break;
            }
        }
        int next = present + arr[right]; // 새로 막는 애가 전체 부피 이하니까 일단 더함
        if (next <= m) { // 더했는데도 전체 부피보다 작으면 갱신
            present = next;
            max = std::max(max, next);
        }
        else { // 커졌으면 왼쪽꺼 하나씩 빼면서 전체 부피 이하 될 때까지 반복
            do {
                next -= arr[left];
                left++;
            } while (next > m); // 전체 부피 이하 되면 갱신
            present = next;
            max = std::max(max, next);
        }
        right++;
    }

    cout << max;

    return 0;
}
