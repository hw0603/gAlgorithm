import sys

N = int(sys.stdin.readline().strip())
playList = list(map(int, sys.stdin.readline().strip().split()))
totalScore = sum(playList)

forwardContSum = [playList[0]] + [0] * (N-1)  # L -> R 연속합
backwardContSum = [0] * (N-1) + [playList[-1]]  # R -> L 연속합

forwardMax = [playList[0]] + [0] * (N-1)  # 각 인덱스까지 L -> R 연속합의 최댓값
backwardMax = [0] * (N-1) + [playList[-1]]  # 각 인덱스까지 R -> L 연속합의 최댓값

# L -> R
for i in range(1, N):
    forwardContSum[i] = max(forwardContSum[i-1] + playList[i], playList[i])  # 이어 가기 vs 새로 시작하기
    forwardMax[i] = max(forwardContSum[i], forwardMax[i-1])  # 현재 인덱스에서 나올 수 있는 부분합의 최댓값

# R -> L
for i in range(N-2, -1, -1):
    backwardContSum[i] = max(backwardContSum[i+1] + playList[i], playList[i])
    backwardMax[i] = max(backwardContSum[i], backwardMax[i+1])

calcByIndex = lambda idx: (forwardMax[idx-1] if idx > 0 else 0) + (backwardMax[idx] if idx < N else 0)
result = max(calcByIndex(i) for i in range(N+1))  # 구간 분할 인덱스별로 시뮬레이션하면서 최댓값 찾음.

print(sum(playList) + max(0, result))  # 추가 재생을 하지 않는 것이 이득인 경우도 있으므로 result의 최솟값은 0
