import sys
from collections import deque

n, q, k = map(int, input().split())

scheduler = deque()

_max = 0
dir = 1
index = q

orders = [[] for _ in range(q)]

for i in range(q):
    orders[i] = list(sys.stdin.readline().strip().split())
    if orders[i][0] == '1':
        index = i

for i in range(q):
    order = orders[i]
    if i == index:
        if dir > 0:
            scheduler = deque(sorted(scheduler, reverse=True))
        else:
            scheduler = deque(sorted(scheduler))
        continue
    if order[0] == '0':
        if dir > 0:
            scheduler.append(int(order[1]))
        else:
            scheduler.appendleft(int(order[1]))
        _max = max(_max, int(order[1]))
    elif order[0] == '2':
        dir *= -1

result = 0

if dir > 0:
    result = scheduler[-k]
else:
    result = scheduler[k-1]

print(result)