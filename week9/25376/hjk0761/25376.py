import sys
from collections import deque

n = int(input())

graph = [[] for _ in range(n+1)]

visited = set()

start_list = list(input().split())

start = 0

for i in range(n):
    if start_list[i] == '1':
        start |=  2 ** i

visited.add(start)

for i in range(n):
    temp = list(map(int, sys.stdin.readline().strip().split()))
    graph[i+1] = temp[1:]
    graph[i+1].append(i+1)

result = -1

def bfs(start):
    global result
    q = deque()
    q.append([start, 0])
    while q:
        cur, depth = q.popleft()
        if cur == 2 ** n - 1:
            result = depth
            break
        for i in range(n):
            temp = cur
            if temp & 2 ** i == 0:
                for j in graph[i+1]:
                    temp ^= 2 ** (j-1)
                if temp not in visited:
                    visited.add(temp)
                    q.append([temp, depth+1])

bfs(start)

print(result)