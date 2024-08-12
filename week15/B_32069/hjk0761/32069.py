import sys
from collections import deque

l, n, k = map(int, input().split())

light = list(map(int, sys.stdin.readline().strip().split()))

visited = set()

q = deque()
count = 0
result = []

for i in range(n):
    q.append((light[i], 0))

while q:
    if count == k:
        break
    loc, weight = q.popleft()

    if loc in visited:
        continue
    if loc < 0 or loc > l:
        continue

    count += 1
    visited.add(loc)

    result.append(weight)

    q.append((loc-1, weight+1))
    q.append((loc+1, weight+1))

for r in result:
    print(r)