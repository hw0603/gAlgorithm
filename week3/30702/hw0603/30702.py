from collections import deque
import sys

dr = (0, 0, 1, -1)
dc = (1, -1, 0, 0)

N, M = map(int, sys.stdin.readline().strip().split())
A = [list(map(ord, sys.stdin.readline().strip())) for _ in range(N)]
B = [list(map(ord, sys.stdin.readline().strip())) for _ in range(N)]

visited = [[False] * M for _ in range(N)]

def bfs(row: int, col: int) -> list[tuple[int, int]]:
    marked = [(row, col)]
    element = A[row][col]
    visited[row][col] = True
    q = deque([(row, col)])

    while (q):
        row, col = q.popleft()
        for i in range(4):
            nr, nc = row+dr[i], col+dc[i]
            if not (0 <= nr < N and 0 <= nc < M):  # 범위밖 Skip
                continue
            if (visited[nr][nc]):  # 재방문 Skip
                continue
            if not (A[nr][nc] == element):  # 첫 원소랑 같지 않으면 다른 구역: Skip
                continue
            marked.append((nr, nc))
            visited[nr][nc] = True
            q.append((nr, nc))
    
    return marked

# 그룹별 좌표 분리
groups = [bfs(i, j) for i in range(N) for j in range(M) if not visited[i][j]]
for group in groups:  # 분리된 그룹 순회하면서 패턴 매칭
    row, col = group[0][0], group[0][1]
    diff = A[row][col] - B[row][col]
    if not (all(diff == (A[i][j] - B[i][j]) for i, j in group)):
        sys.exit(print("NO"))
print("YES")
