import sys

n = int(input())
a = list(map(int, input().split()))

dp = [0] * n
_min = 10000000000

for i in range(n):
    if a[i] < _min:
        _min = a[i]
    dp[i] = max(dp[i-1], a[i] - _min)

print(*dp)