n, m = map(int, input().split())

dp = [[0 for _ in range(26)] for _ in range(m)]

dp[0] = [1 for _ in range(26)]

for i in range(1, m):
    for j in range(26):
        for k in range(26):
            if abs(j - k) >= n:
                dp[i][j] += dp[i-1][k]
        dp[i][j] %= 1000000007
        
print(sum(dp[-1])%1000000007)