import sys
from collections import deque

n, m = map(int, input().split())

board = [[0 for _ in range(m)] for _ in range(n)]

for i in range(n):
    board[i] = list(map(int, sys.stdin.readline().strip().split()))

visited = [[False for _ in range(m)] for _ in range(n)]

dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]

count = 0

def bfs(i, j):
    flag = True
    global visited
    count = 0
    q = deque()
    q.append([i, j])
    visited[i][j] = True
    count += 1
    while q:
        y, x = q.popleft()
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if ny < 0 or ny > n-1 or nx < 0 or nx > m-1:
                continue
            if visited[ny][nx]:
                continue
            if board[ny][nx] == 0:
                flag = False
            if board[ny][nx] == 1:
                continue
            if board[ny][nx] == 2:
                if visited[ny][nx]:
                    continue
                q.append([ny, nx])
                visited[ny][nx] = True
                count += 1
    return count if flag else 0


def find():
    global visited
    temp = 0
    for i in range(n):
        for j in range(m):
            if board[i][j] == 2 and not visited[i][j]:
                temp += bfs(i, j)
    visited = [[False for _ in range(m)] for _ in range(n)]
    return temp

for a in range(n * m -1):
    if board[a//m][a%m] != 0:
        continue
    board[a//m][a%m] = 1
    for b in range(a, n * m):
        if board[b//m][b%m] != 0:
            continue
        board[b//m][b%m] = 1
        count = max(count, find())
        board[b//m][b%m] = 0
    board[a//m][a%m] = 0

print(count)