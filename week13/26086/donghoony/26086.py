import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()
mis = lambda: map(int, input().split())

n, q, k = mis()
query = [list(mis()) for _ in range(q)]
dq = deque()
right = True

def append(x):
    if right: dq.append(x)
    else: dq.appendleft(x)
def pop():
    if right: return dq.pop()
    else: return dq.popleft()

idx = -1
for i in range(q-1, -1, -1):
    if len(query[i]) == 1 and query[i][0] == 1:
        idx = i
        break

arr = []
for i in range(q):
    if i == idx:
        arr.sort()
        dq = deque(arr)
        right = False
        continue
    if query[i][0] == 1:
        continue
    if query[i][0] == 2:
        right = not right
        continue
    append(query[i][1])
    arr += query[i][1],
for i in range(k-1):
    pop()
print(pop())
