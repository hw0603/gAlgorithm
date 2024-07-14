import sys

N, M = map(int, sys.stdin.readline().split())
arr = [0] + sorted(map(int, sys.stdin.readline().strip().split())) + [N+1]
X, Y = map(int, sys.stdin.readline().split())

# manualFixCnt 개의 오류를 직접 해결했을 때 오류 없는 줄이 X줄 이상 연속되는 부분이 있는가?
def check(manualFixCnt: int) -> bool:
    maxCorrectLines = max(arr[i+1]-arr[i-manualFixCnt]-1 for i in range(manualFixCnt, M+1))	
    return maxCorrectLines >= X

# Y개 ~ M개까지의 오류를 해결할 수 있음 -> 근데 직접 해결하는 오류는 최소화해야 함
# F F F 'T' T T
def search() -> int:
	low, high = Y, M
	cur = low - 1
	half_gen = lambda N: (N >> i for i in range(N.bit_length()))

	for step in half_gen(high):
		while (cur+step <= high and not check(cur+step)):
			cur += step
	return cur+1

# 에디터가 해결하는 줄 = 전체 오류 - 직접 해결한 줄
print(M - search())
