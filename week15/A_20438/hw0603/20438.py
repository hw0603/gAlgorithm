from itertools import accumulate
import sys

N, K, Q, M = map(int, sys.stdin.readline().split())  # 학생수, 조는학생수, 출석코드 보낼 학생수, 구간의 수
sleeping = set(map(int, sys.stdin.readline().split()))
checked = [False] * (N+3)

# 출석체크 마킹
for i in map(int, sys.stdin.readline().split()):
    if (i in sleeping):
        continue
    for j in (i for i in range(i, N+3, i) if i not in sleeping):
        checked[j] = True

acc = list(accumulate(checked))

# 쿼리
for _ in range(M):
    S, E = map(int, sys.stdin.readline().split())
    print(E-S+1 - (acc[E] - acc[S-1]))
