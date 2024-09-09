import sys

n, m, t = map(int, input().split())

getIn = [[] for _ in range(t+1)]
getOut = [[] for _ in range(t+1)]

for i in range(n):
    a, b = map(int, sys.stdin.readline().strip().split())
    getIn[a].append(i)
    getOut[b].append(i)

relations = [set() for _ in range(n)]

for i in range(m):
    c, d = map(int, sys.stdin.readline().strip().split())
    relations[c-1].add(d-1)
    relations[d-1].add(c-1)

attendency = [False for _ in range(n)]

result = []

temp = 0

for i in range(t):
    for p in getOut[i]:
        attendency[p] = False
        for f in relations[p]:
            if attendency[f]:
                temp -= 1
    for p in getIn[i]:
        attendency[p] = True
        for f in relations[p]:
            if attendency[f]:
                temp += 1
    result.append(temp)

for re in result:
    print(re)