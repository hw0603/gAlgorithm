from itertools import pairwise
import sys

N, L = map(int, sys.stdin.readline().strip().split())
pos = sorted(map(int, sys.stdin.readline().strip().split()))

result = 0
for idx, (cur, next) in enumerate(pairwise(pos)):
    prev = pos[idx-1] if idx > 0 else -sys.maxsize
    if (cur_right := cur+L) > (next_left := next-L):
        minBound = max(next-L, prev+L)
        result += cur_right - minBound

print(result)
