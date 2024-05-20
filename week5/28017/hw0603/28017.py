from collections import deque
import sys

N, M = map(int, sys.stdin.readline().strip().split())
q = deque([list(map(int, sys.stdin.readline().strip().split())) for _ in range(N)])
dp = [0] * M  # 이전 라운드의 무기 인덱스 별 최적 값

while (q):
    currentRow = q.popleft()
    nextDp = []

    for idx, val in enumerate(currentRow):
        lastRoundMinValue = min(dp)
        if (lastRoundMinValue == dp[idx]):  # 지금 선택하려는 인덱스가 이전에 선택된 인덱스라면
            # 이전 라운드의 두 번째 최적값(두 번쨰로 작은 값)을 사용해야 함
            lastRoundMinValue = sorted(dp)[1]
        nextDp.append(lastRoundMinValue + val)  # 이전 최적값 + 현재 선택한 값-> 현재 선택한 값의 최적값
    
    dp = nextDp

print(min(dp))