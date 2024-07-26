from collections import deque
import sys

N, Q, k = map(int, sys.stdin.readline().split())
query = [tuple(map(int, sys.stdin.readline().split())) for _ in range(Q)]

def solve():
    lastSortQueryIdx = max(idx if q[0] == 1 else 0 for idx, q in enumerate(query))
    leftIO = bool(sum(query[idx][0] == 2 for idx in range(lastSortQueryIdx)) % 2)
    dq = deque(sorted((query[idx][-1] for idx in range(lastSortQueryIdx) if not query[idx][0]), reverse=not leftIO))

    for idx in range(lastSortQueryIdx, Q):
        q, *p = query[idx]
        leftIO ^= bool(q == 2)
        if not (q):
            (lambda x: dq.appendleft(x) if leftIO else dq.append(x))(p[0])  # push
    
    return dq[k-1] if leftIO else dq[len(dq)-k]

print(solve())
