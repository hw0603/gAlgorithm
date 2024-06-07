from collections import deque
import sys

H, W = map(int, sys.stdin.readline().split())
resultMatrix = [list(map(int, sys.stdin.readline().split())) for _ in range(H)]
dr = (0, 0, 1, -1)
dc = (1, -1, 0, 0)


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
    if not (candidate):
        return matrix

    visited = [[False]*W for _ in range(H)]
    maxLight = max(candidate, key=lambda x: x[0])  # 제일 높은 밝기를 가진 조명
    qs = [deque() for _ in range(maxLight[0] + 1)]
    for c in candidate:
        qs[c[0]].append((c[1], c[2]))
        visited[c[1]][c[2]] = True

    # 제일 밝은 조명 밝기부터 밝기를 1씩 낮추며 인접한 좌표에 조명 설치
    for power in range(len(qs)-1, 0, -1):
        q = qs[power]
        while (q):
            row, col = q.popleft()
            matrix[row][col] = power
            for i in range(4):
                nr, nc = row+dr[i] , col+dc[i]
                if not (0 <= nr < H and 0 <= nc < W):
                    continue
                if (matrix[nr][nc] == -1):
                    continue
                if (visited[nr][nc]):
                    continue
                if (power < 1):
                    continue
                visited[nr][nc] = True
                qs[power-1].append((nr, nc))
    return matrix


candidate = [
    (resultMatrix[i][j], i, j) for i in range(H) for j in range(W)
    if (resultMatrix[i][j] > 0 and checkPosition(i, j))
]  # (power, row, col)
matrix = installLight(candidate)

# 조명 설치 후 상태 일치 확인
isAble = all(matrix[r][c] == resultMatrix[r][c] for r in range(H) for c in range(W))
print(len(candidate) if isAble else -1)
