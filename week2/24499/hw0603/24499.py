from itertools import accumulate
import sys

N, K = map(int, sys.stdin.readline().split())
data = list(map(int, sys.stdin.readline().split())) * 2
acc = list(accumulate(data))

print(max(acc[i+K] - acc[i] for i in range(N)))
