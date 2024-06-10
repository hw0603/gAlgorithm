import sys

h, w = map(int, input().split())

dy = [0, -1, 0, 1]
dx = [1, 0, -1, 0]

maze = [[0 for _ in range(w)] for _ in range(h)]

for i in range(h):
    maze[i] = list(map(int, sys.stdin.readline().strip().split()))

light = []
count = 0

possible_maze = True

for i in range(h):
    for j in range(w):
        if not possible_maze:
            break
        if maze[i][j] == -1 or maze[i][j] == 0:
            continue
        possible = True
        for k in range(4):
            ny, nx = i + dy[k], j + dx[k]
            if ny < 0 or ny >= h or nx < 0 or nx >= w:
                continue
            if maze[ny][nx] == -1:
                continue
            if maze[ny][nx] > maze[i][j]:
                possible = False
            if maze[ny][nx] < maze[i][j] - 1 or maze[ny][nx] - 1 > maze[i][j]:
                possible_maze = False
        if possible:
            count += 1
            light.append([i, j])

print(count if possible_maze else -1)