from collections import deque
import sys

N, M = map(int, sys.stdin.readline().split())
matrix = [list(sys.stdin.readline().strip()) for _ in range(N)]
visited = [[False] * M for _ in range(N)]
dr = (1, -1, 0, 0)
dc = (0, 0, 1, -1)
buildings = {}

def findStartPoint():
    for row in range(N):
        for col in range(M):
            if (matrix[row][col] == "@"):
                startRow, startCol = (row, col)
            if (matrix[row][col] == "#"):
                buildings[(row, col)] = 2
            if (matrix[row][col] == "*"):
                buildings[(row, col)] = 1
    
    return startRow, startCol

startRow, startCol = findStartPoint()

destoryCnt, totalCnt = 0, len(buildings)
visited[startRow][startCol] = True

# 진원지로 인한 파급효과들을 다 큐에 넣고 시작
q = deque()
row, col = startRow, startCol
for i in range(4):
    nr, nc = row+dr[i], col+dc[i]
    if not (0 <= nr < N and 0 <= nc < M):
        continue  # 범위밖 Skip
    if (matrix[nr][nc] == '|'):
        continue  # 방파제를 만나면 더 이상 진행하지 않음

    if ((nr, nc) in buildings):
        buildings[(nr, nc)] -= 1
        if (buildings[(nr, nc)] == 0):
            del buildings[(nr, nc)]
            destoryCnt += 1
            q.append((nr, nc))  # 건물이 무너지면 여진 발생 -> 큐에 추가
    
    # 같은방향으로 한 칸 더 가기
    nr += dr[i]
    nc += dc[i]

    if not (0 <= nr < N and 0 <= nc < M):
        continue  # 범위밖 Skip

    if ((nr, nc) in buildings):
        buildings[(nr, nc)] -= 1
        if (buildings[(nr, nc)] == 0):
            del buildings[(nr, nc)]
            destoryCnt += 1
            q.append((nr, nc))  # 건물이 무너지면 여진 발생 -> 큐에 추가

# BFS
while (q):
    row, col = q.popleft()
    for i in range(4):
        nr, nc = row+dr[i], col+dc[i]
        if not (0 <= nr < N and 0 <= nc < M):
            continue  # 범위밖 Skip
        if (matrix[nr][nc] == '|'):
            continue  # 방파제를 만나면 더 이상 진행하지 않음
        if ((nr, nc) in buildings):
            buildings[(nr, nc)] -= 1
            if (buildings[(nr, nc)] == 0):
                del buildings[(nr, nc)]
                destoryCnt += 1
                q.append((nr, nc))  # 건물이 무너지면 여진 발생 -> 큐에 추가

print(destoryCnt, totalCnt-destoryCnt)
