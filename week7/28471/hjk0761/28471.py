import sys
from collections import deque

n = int(input())

board = [['' for _ in range(n)] for _ in range(n)]
visited = [[False for _ in range(n)] for _ in range(n)]

for i in range(n):
    board[i] = list(sys.stdin.readline().strip())

count = 0

dy = [0, 1, 1, 0, -1, -1, -1]
dx = [1, 1, -1, -1, -1, 0, 1]

def dfs(fy, fx):
    count = 0
    q = deque()
    q.append([fy, fx])
    while q:
        y, x = q.popleft()
        for i in range(7):
            ny, nx = y + dy[i], x + dx[i]
            if ny >= 0 and ny < n and nx >= 0 and nx < n:
                if board[ny][nx] == "." and not visited[ny][nx]:
                    visited[ny][nx] = True
                    count += 1
                    q.append([ny, nx])
    return count

yy, xx = 0, 0

for i in range(n):
    for j in range(n):
        if board[i][j] == 'F':
            yy, xx = i, j

print(dfs(yy, xx))