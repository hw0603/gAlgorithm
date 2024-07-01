import sys
from collections import deque

n, m, r = map(int, input().split())

point = list(map(int, sys.stdin.readline().strip().split()))

sides = set()
for i in range(n):
    for j in range(n):
        if i != j:
            sides.add(abs(point[j] - point[i]))
sorted_sides = list(sides)

pole = list(map(int, sys.stdin.readline().strip().split()))
pole.sort()


def binary(dest, target, side):
    left, right = 0, len(target) - 1
    while left <= right:
        mid = (left + right) // 2
        if target[mid] * side / 2 <= dest:
            left = mid + 1
        elif target[mid] * side / 2 > dest:
            right = mid - 1
    return target[left - 1] * side / 2

_max = -1

for side in sorted_sides:
    size = binary(r, pole, side)
    if size <= r:
        _max = max(_max, size)
    if _max == r:
        break

print(_max)