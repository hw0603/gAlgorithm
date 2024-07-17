import sys

n = int(input())

result = 0

rectangle = []

for i in range(n):
    w, h = map(int, sys.stdin.readline().strip().split())
    x, y = w//2, h//2
    rectangle.append([x, y])

rectangle.sort(key = lambda x: (x[0], x[1]), reverse = True)

prev_x, max_y = -1, -1

for i in range(n):
    x, y = rectangle[i]
    if i == 0:
        result += x * y
    else:
        if x == prev_x:
            continue
        else:
            if y > max_y:
                result += x * (y - max_y)
    prev_x, max_y = x, max(max_y, y)

print(result * 4)