import sys


n, m = map(int, input().split())
weapon = [[0 for _ in range(m)] for _ in range(n)]
dp = [[0 for _ in range(m)] for _ in range(n)]

for i in range(n):
    weapon[i] = list(map(int, sys.stdin.readline().strip().split()))

dp[0] = weapon[0]

for i in range(1, n):
    for j in range(m):
        temp = dp[i-1][:]
        temp.remove(dp[i-1][j])
        _min = min(temp)
        dp[i][j] = _min + weapon[i][j]

print(min(dp[n-1]))