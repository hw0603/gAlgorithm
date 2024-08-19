import sys, heapq

n = int(input())

parent = list(map(int, sys.stdin.readline().strip().split()))
node = list(map(int, sys.stdin.readline().strip().split()))

child = [[] for _ in range(n+1)]

for i in range(n-1):
    child[parent[i]].append(i+2)

result = []
q = [(-1 * node[0], 1)]

for i in range(n):
    value, index = heapq.heappop(q)
    if i == 0:
        result.append(value * -1)
    else:
        result.append(result[i-1] + value * -1)
    for c in child[index]:
        heapq.heappush(q, (-1 * node[c-1], c))

for re in result:
    print(re)