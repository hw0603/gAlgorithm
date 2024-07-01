import sys
a, b, c, k = map(int, input().split())

_max = sys.maxsize

dp = [[0 for _ in range(4)] for _ in range(1000001)]
#dp[i][0]: 90 dp[i][1]: 180 dp[i][2]: 270 dp[i][3]: 360(0) in counterclockwise

dp[a][0] = 1
dp[b][2] = 1
dp[c][1] = 1

for i in range(1, k+1):
    for j in range(4):
        if dp[i][j] == 0:
            left = dp[i-a][j-1 if j != 0 else 3] if i > a else 0
            left = left if left != 0 else _max
            right = dp[i-b][j+1 if j != 3 else 0] if i > b else 0
            right = right if right != 0 else _max
            turn = dp[i-c][j-2 if j>1 else j+2]  if i > c else 0
            turn = turn if turn != 0 else _max
            temp = min(left, right, turn)
            dp[i][j] = temp + 1 if temp != _max else 0

print(dp[k][3] if dp[k][3] != 0 else -1)