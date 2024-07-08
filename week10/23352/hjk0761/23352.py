import sys
from collections import deque

n, m = map(int, input().split())

room = [[0 for _ in range(m)] for _ in range(n)]

dy = [1, 0, -1, 0]
dx = [0, -1, 0, 1]

result = [-1, 0]

for i in range(n):
    room[i] = list(map(int, sys.stdin.readline().strip().split()))

def bfs(start):
    board = [[0 for _ in range(m)] for _ in range(n)]
    q = deque()
    q.append(start)
    board[start[0]][start[1]] = 1
    while q:
        y, x = q.popleft()
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if ny < 0 or ny >= n or nx < 0 or nx >= m:
                continue
            if room[ny][nx] == 0:
                continue
            if board[ny][nx] != 0:
                continue
            board[ny][nx] = board[y][x] + 1
            q.append([ny, nx])
    _max = 0
    temp = -1
    for i in range(n):
        for j in range(m):
            if i == start[0] and j == start[1]:
                continue
            if board[i][j] > _max:
                _max = board[i][j]
                temp = room[start[0]][start[1]] + room[i][j]
            elif board[i][j] == _max:
                temp = max(temp, room[start[0]][start[1]] + room[i][j])
    return [_max, temp]

for i in range(n):
    for j in range(m):
        if room[i][j] != 0:
            _tmax, _ttemp = bfs([i, j])
            if _tmax > result[0]:
                result = [_tmax, _ttemp]
            elif _tmax == result[0]:
                result = [result[0], max(_ttemp, result[1])]

print(result[1])