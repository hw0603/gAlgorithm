import sys

n, k, q, m = map(int, input().split())

sleep = list(map(int, sys.stdin.readline().strip().split()))
code = list(map(int, sys.stdin.readline().strip().split()))

student = [0 for _ in range(n+3)]

for s in sleep:
    student[s] = -1

for c in code:
    if c in sleep:
        continue
    index = 1
    while (index * c) <= n+2:
        if student[index * c] != -1:
            student[index * c] = 1
        index += 1

dp = [0 for _ in range(n+3)]

for i in range(3, n+3):
    temp = 0 if student[i] == -1 else student[i]
    dp[i] = dp[i-1] + temp

for _ in range(m):
    s, e = map(int, sys.stdin.readline().strip().split())
    print(e-s+1 - (dp[e] - dp[s-1]))