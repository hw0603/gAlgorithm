import sys

n = int(input())
tanghulu = list(map(int, sys.stdin.readline().strip().split()))

_max = 1

left, right = 0, 0

fruit = [0 for _ in range(9)]
fruit[tanghulu[0]-1] += 1
kind = 1

while True:
    if right == n-1:
        break

    while right < n-1 and (kind != 2 or fruit[tanghulu[right + 1] - 1] != 0):
        right += 1
        fruit[tanghulu[right]-1] += 1
        if fruit[tanghulu[right]-1] == 1:
            kind += 1    
    
    _max = max(_max, right - left + 1)

    fruit[tanghulu[left]-1] -= 1
    if fruit[tanghulu[left]-1] == 0:
        kind -= 1
    left += 1

print(_max)