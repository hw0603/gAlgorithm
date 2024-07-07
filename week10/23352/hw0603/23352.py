from collections import deque
import sys

N, M = map(int, sys.stdin.readline().strip().split())
matrix = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(N)]

dr = (0, 0, 1, -1)
dc = (1, -1, 0, 0)

# 좌표들 중 값이 0이 아닌 좌표들
coords = set((i, j) for i in range(N) for j in range(M) if matrix[i][j])

# value: (pathLength, pw) -> 길이가 길수록, pw값이 클수록..
maxPathPassword = (-1, -1)

# 좌표를 전달받고 해당 좌표를 시작점으로 하는 maxPathPassword 구함
def bfs(row: int, col: int):
    maxPathPassword = (-1, -1)
    startCoordValue = matrix[row][col]
    startCoord = (row, col)
    visited = set()
    q = deque([(row, col)])

    pathLength = 1
    while (q):
        for _ in range(len(q)):
            row, col = q.popleft()
            if ((row, col) != startCoord and (row, col) in coords):
                maxPathPassword = max(maxPathPassword, (pathLength, startCoordValue+matrix[row][col]))
            
            for i in range(4):
                nr, nc = row+dr[i], col+dc[i]
                if not (0 <= nr < N and 0 <= nc < M):
                    continue
                if ((nr, nc) in visited):
                    continue
                if not (matrix[nr][nc]):
                    continue
                visited.add((nr, nc))
                q.append((nr, nc))

        pathLength += 1
    
    return maxPathPassword

for row, col in coords:
    result = bfs(row, col)
    maxPathPassword = max(maxPathPassword, result)

print(max(maxPathPassword[-1], 0))