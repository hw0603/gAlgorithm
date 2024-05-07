from collections import deque

n, m = map(int, input().split())

a = [[] for _ in range(n)]
b = [[] for _ in range(n)]

for i in range(n):
    a[i] = list(input())

for i in range(n):
    b[i] = list(input())

checked = [[False for _ in range(m)] for _ in range(n)]
flag = [['' for _ in range(m)] for _ in range(n)]

stack = [[0, 0]]

dir = [[0, 1], [-1, 0], [0, -1], [1, 0]]

def bfs(cord):
    if checked[cord[0]][cord[1]] == True:
        return
    checked[cord[0]][cord[1]] = True
    q = deque()
    q.append(cord)
    flag[cord[0]][cord[1]] = b[cord[0]][cord[1]]
    while q:
        y, x = q.popleft()
        color = a[y][x]
        for d in dir:
            nx, ny = x + d[0], y + d[1]
            if (nx < 0 or nx > m - 1 or ny < 0 or ny > n - 1):
                continue
            if checked[ny][nx] == False and a[ny][nx] == color:
                checked[ny][nx] = True
                flag[ny][nx] = b[y][x]
                q.append([ny, nx])

for i in range(n):
    for j in range(m):
        bfs([i, j])

if flag == b:
    print("YES")
else:
    print("NO")