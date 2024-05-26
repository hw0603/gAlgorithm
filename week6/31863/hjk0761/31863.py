import sys
from collections import deque

n, m = map(int, input().split())

d = [[0, 1], [-1, 0], [0, -1], [1, 0]]

street = [['' for _ in range(m)] for _ in range(n)]
count = [[0 for _ in range(m)] for _ in range(n)]

stand = 0
fallen = 0

for i in range(n):
    street[i] = list(sys.stdin.readline().strip())

def bfs(y, x):
    global stand, fallen
    q = deque()
    q.append([y, x])
    ty, tx = q.popleft()
    for dy, dx in d:
        ny, nx = ty + dy, tx + dx
        if ny >= 0 and ny <= n-1 and nx >= 0 and nx <= m-1:
            if street[ny][nx] == '|':
                continue
            elif street[ny][nx] == '*':
                street[ny][nx] = '.'
                q.append([ny, nx])
                fallen += 1
                stand -= 1
            elif street[ny][nx] == '#':
                if count[ny][nx] < 1:
                    count[ny][nx] += 1
                else:
                    street[ny][nx] = '.'
                    q.append([ny, nx])
                    fallen += 1
                    stand -= 1
        ny, nx = ny + dy, nx + dx
        if ny >= 0 and ny <= n-1 and nx >= 0 and nx <= m-1:
            if street[ny][nx] == '|':
                continue
            elif street[ny][nx] == '*':
                street[ny][nx] = '.'
                q.append([ny, nx])
                fallen += 1
                stand -= 1
            elif street[ny][nx] == '#':
                if count[ny][nx] < 1:
                    count[ny][nx] += 1
                else:
                    street[ny][nx] = '.'
                    q.append([ny, nx])
                    fallen += 1
                    stand -= 1
    while q:
        ty, tx = q.popleft()
        for dy, dx in d:
            ny, nx = ty + dy, tx + dx
            if ny >= 0 and ny <= n-1 and nx >= 0 and nx <= m-1:
                if street[ny][nx] == '|':
                    continue
                elif street[ny][nx] == '*':
                    street[ny][nx] = '.'
                    q.append([ny, nx])
                    fallen += 1
                    stand -= 1
                elif street[ny][nx] == '#':
                    if count[ny][nx] < 1:
                        count[ny][nx] += 1
                    else:
                        street[ny][nx] = '.'
                        q.append([ny, nx])
                        fallen += 1
                        stand -= 1

y, x = -1, -1

for i in range(n):
    for j in range(m):
        if street[i][j] == '@':
            y, x = i, j
        elif street[i][j] == '*' or street[i][j] == '#':
            stand += 1

bfs(y, x)

print(str(fallen) + ' ' + str(stand))