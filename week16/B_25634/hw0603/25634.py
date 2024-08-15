import sys

N = int(sys.stdin.readline().strip())
A = list(map(int, sys.stdin.readline().strip().split()))
B = list(map(int, sys.stdin.readline().strip().split()))
dp = [-sys.maxsize] * N

originValue = sum([A[i] for i in range(N) if B[i]])

for i in range(N):
    dp[i] = (-A[i] if B[i] else A[i]) + max(dp[i-1], 0)  # 지금꺼만 바꾸는거 vs 앞에꺼랑 같이 바꾸는거

print(originValue + max(dp))
