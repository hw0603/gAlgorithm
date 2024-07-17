import sys, heapq

n = int(input())

_max = sys.maxsize

field = [[0 for _ in range(n)] for _ in range(n)]

dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]

for i in range(n):
    field[i] = list(map(int, sys.stdin.readline().strip().split()))

visited = [[_max for _ in range(n)] for _ in range(n)]

def dijkstra(start_y, start_x):
    hq = []
    heapq.heappush(hq, (0, start_y, start_x))
    visited[start_y][start_x] = 0
    while hq:
        h, y, x = heapq.heappop(hq)
        if visited[y][x] < h:
            continue
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if ny < 0 or ny > n-1 or nx < 0 or nx > n-1:
                continue
            nh = max(h, abs(field[ny][nx] - field[y][x]))
            if nh < visited[ny][nx]:
                visited[ny][nx] = nh
                heapq.heappush(hq, (nh, ny, nx))

dijkstra(0, 0)

print(visited[n-1][n-1])