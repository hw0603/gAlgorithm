import sys
import heapq

n, m = map(int, input().split())

graph = [[] for _ in range(n)]

for i in range(m):
    u, v, d, t = map(int, sys.stdin.readline().strip().split())
    graph[u-1].append((v-1, d, t))
    graph[v-1].append((u-1, d, t))

def dijkstra(graph, start):
    visited = [False for _ in range(n)]
    result = [-1 for _ in range(n)]
    q = []
    heapq.heappush(q, (-10000000000, 0, start))
    while q:
        latest_time, min_time, node = heapq.heappop(q)
        visited[node] = True
        if result[node] == -1:
            result[node] = -1 * latest_time
        else:
            result[node] = max(result[node], -1 * latest_time)
        for next, d, t in graph[node]:
            if visited[next] or min_time > t - d:
                continue
            next_latest_time = -1 * min(-1 * latest_time - d,  t - d)
            next_min_time = min_time + d
            heapq.heappush(q, (next_latest_time, next_min_time, next))

    return result[n-1-start]

print(dijkstra(graph, n-1))