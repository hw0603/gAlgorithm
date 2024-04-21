import sys
n, k = map(int, sys.stdin.readline().strip().split())

pieces = set()
for _ in range(k):
    x, y = map(int, sys.stdin.readline().strip().split())
    pieces.add((x, y))

possible = set()

movement = [[0, 2], [2, 0], [-2, 0], [0, -2]]

for x, y in pieces:
    for dx, dy in movement:
        nx, ny = x + dx, y + dy
        if nx < 1 or nx > n or ny < 1 or ny > n or (nx, ny) in pieces:
            continue
        possible.add((nx, ny))
print(len(possible))