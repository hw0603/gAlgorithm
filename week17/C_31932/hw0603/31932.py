import heapq
import sys

N, M = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(N+1)]

for _ in range(M):
    u, v, d, t = map(int, sys.stdin.readline().split())
    graph[u].append((v, d, t))
    graph[v].append((u, d, t))

# 결정함수: time 에 출발하면 집에 갈 수 있나?
def dijkstra(time: int) -> bool:
    dist = [sys.maxsize] * (N+1)
    dist[1] = time
    pq = [(time, 1)]  # (time, node): node 에서 time에 출발함

    while (pq):
        curTime, curNode = heapq.heappop(pq)
        if (curNode == N):
            return True  # 집 도착
        
        # 가지치기: 이전에 구해둔 값보다 큐에서 pop()한게 크면 볼 필요도 x
        if (curTime > dist[curNode]):
            continue
        
        for nextNode, bridgeLength, bridgeTime in graph[curNode]:
            nextTime = curTime + bridgeLength
            # 무너지는 다리는 건널 수 없음
            if (nextTime > bridgeTime):
                continue
            # 현재 알려진 시간보다 더 이르게 방문할 수 있으면 갱신
            if (nextTime < dist[nextNode]):
                dist[nextNode] = nextTime
                heapq.heappush(pq, (nextTime, nextNode))
    
    return False

# T T 'T' F F 찾기
def binaryJump():
    low, high = 0, 10**9
    cur = low - 1
    step = high

    while (step):
        while (cur + step <= high and dijkstra(cur+step)):
            cur += step
        step //= 2
    
    return cur

print(binaryJump())
