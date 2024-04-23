import sys

N, K = map(int, sys.stdin.readline().split())

dr = (-2, 2, 0, 0)
dc = (0, 0, -2, 2)

destinations = set()
piecePositions = set()

for _ in range(K):
    row, col = map(int, sys.stdin.readline().split())
    piecePositions.add((row, col))

    for i in range(4):
        nr, nc = row+dr[i], col+dc[i]
        if not (0 < nr <= N and 0 < nc <= N):
            continue
        destinations.add((nr, nc))

print(len(destinations - piecePositions))
