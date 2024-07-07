import sys

N = int(sys.stdin.readline().strip())
scores = list(map(int, sys.stdin.readline().split()))
p, q, r, S = map(int, sys.stdin.readline().split())

def proceed(score: int, K: int) -> int:
    if (score > K+r):
        return score-p
    if (score < K):
        return score+q
    return score

# K를 받아서 청소를 해야 하는지 안 해도 되는지 확인
def check(K: int) -> bool:
    return True if sum(map(lambda s: proceed(s, K), scores)) < S else False


# 매개 변수 탐색 -> T T T 'F' F F  구하기
def half_gen(N):
	while (N):
		yield N
		N //= 2

def search():
	low, high = 1, 110_000
	cur = low - 1
	
	for step in half_gen(high):
		while (cur+step <= high and check(cur+step)):
			cur += step
	return cur+1

result = search()
print(result if result <= 110_000 else -1)
# https://ws-pace.tistory.com/212