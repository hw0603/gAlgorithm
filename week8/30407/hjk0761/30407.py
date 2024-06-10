n = int(input())
h, d, k = map(int, input().split())

punch = [0 for _ in range(n)]
for i in range(n):
    punch[i] = int(input())

damage = 999999999

dp = [[0 for _ in range(n+1)] for _ in range(n+1)]

for i in range(n+1):
    for j in range(n+1):
        if j == 0:
            continue
        if i < j:
            dp[i][j] = max(0, (punch[j-1] - d - k * i) // 2)
        elif i == j:
            dp[i][j] = max(0, punch[j-1] - d - k * i)
        else:
            dp[i][j] = dp[i-1][j]

for i in range(n+1):
    damage = min(damage, sum(dp[i]))

for i in range(n):
    for j in range(1, n-1):
        surprise = 0
        for k in range(j):
            surprise += dp[i][k]
        surprise += max(0, punch[j-1] - d - k * i)
        for k in range(j+2, n+1):
            surprise += dp[i+1][k]
        damage = min(damage, surprise)
        print(damage)

print(h - damage if h > damage else -1)