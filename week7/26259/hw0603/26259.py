from collections import deque
import sys

N, M = map(int, sys.stdin.readline().split())
matrix = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
x1, x2, y1, y2 = min(x1, x2), max(x1, x2), min(y1, y2), max(y1, y2)

# 아래, 오른쪽
dr = (1, 0)
dc = (0, 1)

def createBlockedArea(x1, y1, x2, y2):
    blockedData = {}
    if ((x1, y1) == (x2, y2)):
        return {}
    
    # 가로선
    if (x1 == x2):
        if (x1 in {0, N}):  # 최상단과 최하단 줄에 있는 벽은 진행에 영향을 미치지 못함
            return {}
        for col in range(y1, y2):
            blockedData[(x1-1, col)] = (1, 0)  # 밑으로 못감
            cache[(x1, col)] = -sys.maxsize  # 벽에 의해서 한번밖에 방문하지 못하는 곳들
        # 만약 0행 또는 0열부터 바로 벽이 있다면 해당 벽 아래 혹은 우측은 아예 방문하지 못함
        # -> 진행방향 기준 방문 불가 영역 바로 옆칸을 전부 1회 기 방문처리
        if (y1 == 0):
            for r in range(x1, N):
                cache[(r, y2)] = -sys.maxsize

    # 세로선
    if (y1 == y2):
        if (y1 in {0, M}):
            return {}
        for row in range(x1, x2):
            blockedData[(row, y1-1)] = (0, 1)  # 오른쪽으로 못감
            cache[(row, y1)] = -sys.maxsize
        if (x1 == 0):
            for c in range(y1, M):
                cache[(x2, c)] = -sys.maxsize

    return blockedData


# 가장 위쪽과 가장 왼쪽 좌표들은 캐시에 미리 넣어 두어야 함
cache = {}
for row in range(N):
    cache[(row, 0)] = -sys.maxsize
for col in range(M):
    cache[(0, col)] = -sys.maxsize

blockedData = createBlockedArea(x1, y1, x2, y2)  # key: 좌표, val: 금지된 (dr, dc)


# BFS
q = deque([(0, 0, matrix[0][0])])
result = -sys.maxsize
while (q):
    row, col, acc = q.popleft()

    if ((row, col) == (N-1, M-1)):
        result = max(result, acc)

    for i in range(2):
        nr, nc = row+dr[i], col+dc[i]
        if ((row, col) in blockedData and blockedData[(row, col)] == (dr[i], dc[i])):
            continue
        if not (0 <= nr < N and 0 <= nc < M):
            continue

        # 캐시에 있을 때(=두 번째 방문 시)
        if ((nr, nc) in cache):
            value = max(cache[(nr, nc)], acc+matrix[nr][nc])
            q.append((nr, nc, value))
        else:
            cache[(nr, nc)] = acc+matrix[nr][nc]

print(result if result != -sys.maxsize else "Entity")
