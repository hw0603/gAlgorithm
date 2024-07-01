import sys

A, B, C, K = map(int, sys.stdin.readline().strip().split())
INF = float('inf')
# key: 에너지, value: 추가되는 동작 횟수
data = {
    A+A+A+A: 4,  # 좌 좌 좌 좌
    B+B+B+B: 4,  # 우 우 우 우
    A+A+C: 3,  # 좌 좌 뒤
    B+B+C: 3,  # 우 우 뒤
    A+B: 2,  # 좌 우
    C+C: 2,  # 뒤 뒤
}  # Key가 동일한 경우 값이 덮어씌워짐 -> 값 내림차순으로 정의해야 함
dp = [0] * (K+1)  # dp[i] = i만큼의 에너지를 사용하고 원래 방향을 보는 최소 동작 횟수

calcDp = lambda energy, x: dp[energy-x] + data[x] if energy >= x else INF
for energy in range(1, K+1):
    dp[energy] = min(calcDp(energy, e) for e in data.keys())

print(dp[K] if dp[K] != INF else -1)
