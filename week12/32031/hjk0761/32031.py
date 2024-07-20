import sys
from collections import deque

r, c = map(int, input().split())

frame = [['' for _ in range(c)] for _ in range(r)]

for i in range(r):
    frame[i] = list(sys.stdin.readline().strip())

dy = [1, 0, -1, 0, 0]
dx = [0, 1, 0, -1, 0]

result = 0

graph = [[] for _ in range((r+1)*(c+1))]

for i in range(r):
    for j in range(c):
        if frame[i][j] == 'O':
            graph[i*(c+1)+j].append(i*(c+1)+j)
            graph[i*(c+1)+j+1].append(i*(c+1)+j+1)
            graph[(i+1)*(c+1)+j].append((i+1)*(c+1)+j)
            graph[(i+1)*(c+1)+j+1].append((i+1)*(c+1)+j+1)
        elif frame[i][j] == 'I':
            graph[i*(c+1)+j].append((i+1)*(c+1)+j)
            graph[(i+1)*(c+1)+j].append(i*(c+1)+j)
            graph[i*(c+1)+j+1].append((i+1)*(c+1)+j+1)
            graph[(i+1)*(c+1)+j+1].append(i*(c+1)+j+1)
        else:
            graph[i*(c+1)+j].append(i*(c+1)+j+1)
            graph[i*(c+1)+j+1].append(i*(c+1)+j)
            graph[(i+1)*(c+1)+j].append((i+1)*(c+1)+j+1)
            graph[(i+1)*(c+1)+j+1].append((i+1)*(c+1)+j)

visited = [False for _ in range((r+1)*(c+1))]

def bfs(ver, hor):
    connected = False
    q = deque()
    q.append([ver, hor])
    visited[ver*(c+1) + hor] = True
    while q:
        y, x = q.popleft()
        for index in graph[y*(c+1)+x]:
            ny, nx = index//(c+1), index%(c+1)
            if ny == y and nx == x:
                connected = True
            if visited[ny*(c+1) + nx]:
                continue
            visited[ny*(c+1) + nx] = True
            q.append([ny, nx])
    return connected

for i in range(r+1):
    for j in range(c+1):
        if not visited[i*(c+1) + j]:
            connected = bfs(i, j)
            if connected:
                result += 1
            else:
                result += 2
            
print(result)