import sys, heapq

n = int(input())

statue = list(map(int, sys.stdin.readline().strip().split()))

one = [0 for _ in range(n)]
two = [0 for _ in range(n)]

temp = 0

for i in range(n):
    if i == 0:
        one[i] = 1 if statue[i] == 1 else 0
        temp = 1 if statue[i] == 1 else 0
    else:
        a = 1 if statue[i] == 1 else -1
        one[i] = max(one[i-1], a + temp)
        if statue[i] == 1:
            temp += 1
        else:
            temp = max(0, temp - 1)

temp = 0

for i in range(n):
    if i == 0:
        two[i] = 1 if statue[i] == 2 else 0
        temp = 1 if statue[i] == 2 else 0
    else:
        a = 1 if statue[i] == 2 else -1
        two[i] = max(two[i-1], a + temp)
        if statue[i] == 2:
            temp += 1
        else:
            temp = max(0, temp - 1)

print(max(one[-1], two[-1]))