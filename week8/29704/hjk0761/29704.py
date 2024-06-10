import sys

n, t = map(int, input().split())

problem = [[0, 0] for _ in range(n)]

w = [0 for _ in range(n+1)]
v = [0 for _ in range(n+1)]

_sum = 0

for i in range(n):
    problem[i] = list(map(int, sys.stdin.readline().strip().split()))
    _sum += problem[i][1]
    w[i+1] = problem[i][0]
    v[i+1] = problem[i][1]

dp = [[0 for _ in range(t+1)] for _ in range(n+1)]

for i in range(1, n+1):
    for j in range(1, t+1):
        if j - w[i] >= 0:
            dp[i][j] = max(dp[i-1][j], dp[i - 1][j - w[i]] + v[i])
        else:
            dp[i][j] = dp[i-1][j]

print(_sum - dp[n][t])