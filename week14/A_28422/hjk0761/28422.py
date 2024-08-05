import sys

n = int(input())

deck = list(map(int, sys.stdin.readline().strip().split()))

dp = [0 for _ in range(n)]

def count(binary):
    temp = 0
    while binary > 0:
        temp += binary % 2
        binary //= 2
    return temp

for i in range(n):
    if i == 0:
        continue
    if i == 1:
        dp[i] = count(deck[0] ^ deck[1])
        continue
    if i == 2:
        dp[i] = count(deck[0] ^ deck[1] ^ deck[2])
        continue
    if i == 3:
        dp[i] = dp[i-2] + count(deck[i-1] ^ deck[i])
        continue
    dp[i] = max(dp[i-2] + count(deck[i-1] ^ deck[i]), dp[i-3] + count(deck[i-2] ^ deck[i-1] ^ deck[i]))
    
print(dp[n-1])