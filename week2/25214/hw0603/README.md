## Info
[25214 크림 파스타](https://www.acmicpc.net/problem/25214)

## 💡 풀이 방법 요약
DP. 각 인덱스별로 현재 상태의 최적 값을 유지해 두고, 새로 들어온 수를 `Aj`로 택했을 때 직전의 값보다 더 크게 만들 수 있다면 새로운 수를 택한다.  
  
문제 조건에 의해 `Aj - Ai, (i <= j)` 의 최댓값을 구해야 하므로, 어떤 수를 `Aj` 로 택하냐에 따라 `Ai`로 선택할 수 있는 수들의 범위가 달라지게 된다.
  
생각해 보면, 새로 들어오는 수의 인덱스는 항상 이전 수보다 크기 때문에 `Ai`는 현재까지 나왔던 수들 중 가장 작은 수를 택하면 된다.  
처음에는 이 부분을 놓쳐서 아래와 같이 이진탐색..으로 풀이했었다.
```python
from bisect import bisect_left
import sys

N = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

minValue = sys.maxsize

minData = []  # (idx, val) -> idx 인덱스부터는 val을 최솟값으로 사용 가능
for idx, num in enumerate(arr):
    if (num < minValue):
        minValue = num
        minData.append((idx, num))

dp = [0] * N
for idx, num in enumerate(arr):
    # 새로 들어온 값을 max로 쓰거나, 이전 최적 값을 그대로 가져가거나
    newValue = num - minData[bisect_left(minData, (idx, sys.maxsize)) - 1][-1]
    dp[idx] = max(dp[idx-1], newValue)

print(*dp)
```


## 🙂 마무리
숏코딩의 매력

```python
# 풀어쓴 버전
minValue = sys.maxsize
dp = [0] * N
for idx, num in enumerate(arr):
    minValue = min(minValue, num)
    dp[idx] = max(dp[idx-1], num - minValue)

print(*dp)
```