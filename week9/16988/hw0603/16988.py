from itertools import combinations
from collections import deque
import sys

EMPTY, ME, AI = 0, 1, 2
N, M = map(int, sys.stdin.readline().strip().split())
matrix = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(N)]
dr = (0, 0, 1, -1)
dc = (1, -1, 0, 0)

# 상대의 말에 인접해 있으면서 빈 칸인 좌표가 착수 위치 후보군이 됨
def findIsland(row, col):
    initialVisitedCnt = len(visited)
    adjEmptyCoords = set()
    visited.add((row, col))
    q = deque([(row, col)])
    while (q):
        row, col = q.popleft()
        for i in range(4):
            nr, nc = row+dr[i], col+dc[i]
            if not (0 <= nr < N and 0 <= nc < M):
                continue
            if ((nr, nc) in visited):
                continue
            if (matrix[nr][nc] == EMPTY):
                adjEmptyCoords.add((nr, nc))
                continue
            if (matrix[nr][nc] != AI):
                continue
            visited.add((nr, nc))
            q.append((nr, nc))
    
    return adjEmptyCoords, len(visited) - initialVisitedCnt


visited = set()
candidates = set()
islandSize = {}
islandSafeBy = {}
for i in range(N):
    for j in range(M):
        if (matrix[i][j] != AI):
            continue
        if ((i, j) in visited):
            continue
        adjCoords, size = findIsland(i, j)
        if (len(adjCoords) > 2):
            continue  # 두개 이상의 빈칸에 인접한 섬들은 절대 못 먹음

        candidates.update(adjCoords)
        islandSize[(i, j)] = size  # 각 섬의 대표 좌표들을 저장
        islandSafeBy[(i, j)] = adjCoords

def simulate(coord1, coord2):
    score = 0
    pairSet = set([coord1, coord2])
    for rep in islandSafeBy:
        if (len(islandSafeBy[rep] - pairSet) == 0):
            score += islandSize[rep]
    
    return score

result = 0
for coord1, coord2 in combinations(candidates, 2):
    result = max(result, simulate(coord1, coord2))
if (len(candidates) == 1):
    result = max(result, simulate(candidates.pop(), None))

print(result)