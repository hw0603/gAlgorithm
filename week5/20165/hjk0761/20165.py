import sys
from collections import deque

n, m, r = map(int, input().split())

status = [[0 for _ in range(m)] for _ in range(n)]
board = [['S' for _ in range(m)] for _ in range(n)]

for i in range(n):
    status[i] = list(map(int, sys.stdin.readline().strip().split()))

score = 0

for _ in range(r):
    a_x, a_y, d = sys.stdin.readline().strip().split()
    a_x, a_y = int(a_x) - 1, int(a_y) - 1

    temp_score = 0

    if board[a_x][a_y] == 'S':
        q = deque()
        q.append([a_x, a_y])
        if d == 'E':
            while q:
                x, y = q.popleft()
                if board[x][y] == 'S':
                    temp_score += 1
                    board[x][y] = 'F'
                    for i in range(1, status[x][y]):
                        if y + i > m-1:
                            break
                        q.append([x, y+i])
        elif d == 'S':
            while q:
                x, y = q.popleft()
                if board[x][y] == 'S':
                    temp_score += 1
                    board[x][y] = 'F'
                    for i in range(1, status[x][y]):
                        if x + i > n-1:
                            break
                        q.append([x+i, y])
        elif d == 'W':
            while q:
                x, y = q.popleft()
                if board[x][y] == 'S':
                    temp_score += 1
                    board[x][y] = 'F'
                    for i in range(1, status[x][y]):
                        if y - i < 0:
                            break
                        q.append([x, y-i])
        elif d == 'N':
            while q:
                x, y = q.popleft()
                if board[x][y] == 'S':
                    temp_score += 1
                    board[x][y] = 'F'
                    for i in range(1, status[x][y]):
                        if x - i < 0:
                            break
                        q.append([x-i, y])

    score += temp_score

    d_x, d_y = map(int, sys.stdin.readline().strip().split())
    board[d_x - 1][d_y - 1] = 'S'

print(score)
for i in range(n):
    for j in range(m):
        print(board[i][j], end = ' ')
    print()