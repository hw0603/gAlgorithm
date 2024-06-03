from collections import deque
import sys

def solution():
    # 아래쪽 이동 빠진 7방향
    dr = (0, -1, 0, -1, -1, 1, 1)
    dc = (1, 0, -1, 1, -1, 1, -1)

    N = int(sys.stdin.readline())
    matrix = [list(sys.stdin.readline().strip()) for _ in range(N)]
    visited = [[False] * N for _ in range(N)]

    for i in range(N):
        for j in range(N):
            if (matrix[i][j] == 'F'):
                row, col = i, j

    visited[row][col] = True
    q = deque([(row, col)])
    result = 0
    while (q):
        row, col = q.popleft()
        for i in range(7):
            nr, nc = row+dr[i], col+dc[i]
            if not (0 <= nr < N and 0 <= nc < N):
                continue
            if (visited[nr][nc]):
                continue
            if (matrix[nr][nc] in {'#', 'F'}):
                continue

            visited[nr][nc] = True
            result += 1
            q.append((nr, nc))

    return result

print(solution())
