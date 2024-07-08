import sys

n, m = map(int, input().split())

path = []

union = [i for i in range(n+1)]

result = 0

univ = list(sys.stdin.readline().strip().split())

for i in range(m):
    u, v, d = map(int, sys.stdin.readline().strip().split())
    if univ[u-1] == univ[v-1]:
        continue
    path.append([u, v, d])

path.sort(key = lambda x: x[2])

for u, v, d in path:
    if union[u] == union[v]:
        continue
    result += d
    next = min(union[u], union[v])
    prev = max(union[u], union[v])
    union[u] = next
    union[v] = next
    for i in range(1, n+1):
        if union[i] == prev:
            union[i] = next

flag = True
for i in range(1, n):
    if union[i] != union[i+1]:
        flag = False
        break

print(result if flag else -1)