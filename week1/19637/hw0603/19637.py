from bisect import bisect_left
import sys

N, M = map(int, sys.stdin.readline().split())

data = []
for idx in range(N):
    level, threshold = sys.stdin.readline().strip().split()
    data.append((int(threshold), idx, level))
data.sort()

result = (
    data[bisect_left(data, (int(sys.stdin.readline()), -1, ''))][-1]
    for _ in range(M)
)
print(*result, sep='\n')
