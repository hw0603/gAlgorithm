from bisect import bisect_left
from itertools import accumulate
import sys

N, Q = map(int, sys.stdin.readline().strip().split())
positions = sorted(map(int, sys.stdin.readline().strip().split()))
acc = list(accumulate(positions))
photo = [int(sys.stdin.readline()) for _ in range(Q)]

def calcScore(photo: int) -> int:
    idx = bisect_left(positions, photo)
    left = (idx*photo) - acc[idx-1]
    left = 0 if idx == 0 else left

    right = (acc[-1]-(acc[idx-1] if idx != 0 else 0)) - photo*(N - idx)

    return left+right

print(*(calcScore(p) for p in photo), sep="\n")
