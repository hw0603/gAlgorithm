import sys

N = int(sys.stdin.readline())
cards = [0] + list(map(int, sys.stdin.readline().split()))

dp = [0] * (N+10)  # i번째 카드까지 조사했을 때, 최대 점수. dp[0] = dp[1] = 0

# Base Condition
dp[2] = (cards[1] ^ cards[2]).bit_count() if N >= 2 else 0
dp[3] = (cards[1] ^ cards[2] ^ cards[3]).bit_count() if N >= 3 else 0
dp[4] = dp[2] + (cards[3] ^ cards[4]).bit_count() if N >= 4 else 0

for i in range(5, N+1):
    pick2 = cards[i] ^ cards[i-1]  # 2장
    pick3 = cards[i] ^ cards[i-1] ^ cards[i-2]  # 3장
    dp[i] = max(dp[i-2] + pick2.bit_count(), dp[i-3] + pick3.bit_count())

print(dp[N])
