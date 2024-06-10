n = int(input())

corridor = [['' for _ in range(n)] for _ in range(n)]

for i in range(n):
    corridor[i] = list(input().split())

dir = [[0, 1], [-1, 0], [0, -1], [1, 0]]

possibility = False

for i in range(n**2 - 2):
    ay, ax = i//n, i%n
    if corridor[ay][ax] != 'X':
        continue
    for j in range(i+1, n**2 - 1):
        by, bx = j//n, j%n
        if corridor[by][bx] != 'X':
            continue
        for k in range(j+1, n**2):
            cy, cx = k//n, k%n
            if corridor[cy][cx] != 'X':
                continue
            possible = True
            for y in range(n):
                for x in range(n):
                    if corridor[y][x] == 'T':
                        for dy, dx in dir:
                            ny, nx = y + dy, x + dx
                            while ny >= 0 and ny < n and nx >= 0 and nx < n:
                                if (ny == ay and nx == ax) or (ny == by and nx == bx) or (ny == cy and nx == cx):
                                    break
                                if corridor[ny][nx] == 'S':
                                    possible = False
                                ny, nx = ny + dy, nx + dx
            if possible:
                possibility = True

print("YES" if possibility else "NO")