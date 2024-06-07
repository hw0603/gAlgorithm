import heapq
import sys

H, W = map(int, sys.stdin.readline().split())
resultMatrix = [list(map(int, sys.stdin.readline().split())) for _ in range(H)]
dr = (0, 0, 1, -1)
dc = (1, -1, 0, 0)

# H, W = 1000, 1000
# resultMatrix = [[10000]*W for _ in range(H)]


def checkPosition(row, col):
    myValue = resultMatrix[row][col]
    maxValue = -1
    for i in range(4):
        nr, nc = row+dr[i], col+dc[i]
        if not (0 <= nr < H and 0 <= nc < W):
            continue
        maxValue = max(maxValue, resultMatrix[nr][nc])
    return True if myValue >= maxValue else False


def installLight(candidate: list):
    matrix = [[min(resultMatrix[i][j], 0) for j in range(W)] for i in range(H)]
    # visited = set([(c[1], c[2]) for c in candidate])
    visited = [[False]*W for _ in range(H)]
    for c in candidate:
        visited[c[1]][c[2]] = True
    while (candidate):
        power, row, col = heapq.heappop(candidate)
        power *= -1
        matrix[row][col] = power
        for i in range(4):
            nr, nc = row+dr[i] , col+dc[i]
            if not (0 <= nr < H and 0 <= nc < W):
                continue
            if (matrix[nr][nc] == -1):
                continue
            if (visited[nr][nc]):
                continue
            if (power-1 < 1):
                continue
            visited[nr][nc] = True
            heapq.heappush(candidate, (-(power-1), nr, nc))
    return matrix

import time
t = time.time()


candidate = []  # (-power, row, col) -> power 기준 내림차순 정렬
for i in range(H):
    for j in range(W):
        if (resultMatrix[i][j] > 0 and checkPosition(i, j)):
            heapq.heappush(candidate, (-resultMatrix[i][j], i, j))
candidateCnt = len(candidate)
matrix = installLight(candidate)

# 조명 설치 후 상태 일치 확인
isAble = all(matrix[r][c] == resultMatrix[r][c] for r in range(H) for c in range(W))
print(candidateCnt if isAble else -1)
print(time.time() - t)