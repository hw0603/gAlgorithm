import sys
from collections import deque

n, m = map(int, input().split())

backroom = [[0 for _ in range(m)] for _ in range(n)]

for i in range(n):
    backroom[i] = list(map(int, sys.stdin.readline().strip().split()))

dp = [[-999999999 for _ in range(m+1)] for _ in range(n+1)]

y1, x1, y2, x2 = map(int, input().split())
y1, y2, x1, x2 = min(y1, y2), max(y1, y2), min(x1, x2), max(x1, x2)

for i in range(n):
    for j in range(m):
        if i == 0 and j == 0:
            dp[1][1] = backroom[0][0]
            continue
        if (y1 == y2 and i == y1 and j >= x1 and j < x2):
            if j == 0 or dp[i+1][j] == -999999999:
                continue
            dp[i+1][j+1] = backroom[i][j] + dp[i+1][j]
        elif (x1 == x2 and j == x1 and i >= y1 and i < y2):
            if i == 0 or dp[i][j+1] == -999999999:
                continue
            dp[i+1][j+1] = backroom[i][j] + dp[i][j+1]
        else:
            dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]) + backroom[i][j]

print(dp[n][m] if dp[n][m] != -999999999 else "Entity")