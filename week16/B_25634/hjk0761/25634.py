import sys

n = int(input())

bulb = list(map(int, sys.stdin.readline().strip().split()))
setting = list(map(int, sys.stdin.readline().strip().split()))

_sum = sum([bulb[i] * setting[i] for i in range(n)])

value = [0 for _ in range(n)]

for i in range(n):
    value[i] = bulb[i] if setting[i] == 0 else -1 * bulb[i]

dp = [0 for _ in range(n)]
temp = 0

for i in range(n):
    if i == 0:
        dp[i] = max(0, value[i])
        temp = max(0, value[i])
        continue
    dp[i] = max(dp[i-1], value[i] + temp)
    if value[i] >= 0:
        temp += value[i]
    else:
        temp = max(0, temp + value[i])

print(_sum + dp[-1]) if _sum != sum(bulb) else print(_sum - min(bulb))