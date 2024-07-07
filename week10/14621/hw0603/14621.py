import sys
import heapq

N, M = map(int, sys.stdin.readline().split())
univType = [None] + sys.stdin.readline().split()
visited = [False]*(N+1)
adjList = [[] for _ in range(N+1)]

# 인접리스트 구축
for _ in range(M):
    n1, n2, w = map(int, sys.stdin.readline().split())
    adjList[n1].append((w, n2))  # (가중치, 노드번호) -> Min Heap
    adjList[n2].append((w, n1))

totalDist = 0
cnt = 0  # 현재까지 선택된 간선 수
pq = [(0, 1, None, univType[1])]  # 최초 MST 집합. (dist, node, adjNodeType, type)

while (pq):
    dist, node, adjNodeType, currentNodeType = heapq.heappop(pq)
    if (visited[node]):
        continue  # 이미 방문한 정점 Skip
    if (adjNodeType == currentNodeType):
        continue  # 현재노드와 같은 타입의 노드 Skip

    visited[node] = True  # 방문 처리하고
    totalDist += dist  # 경로 길이 누적
    cnt += 1

    for adjDist, adjNode in adjList[node]:  # 그 정점과 인접한 노드들의 정보를 pq에 push()
        if (visited[adjNode]):
            continue
        if (univType[adjNode] == currentNodeType):
            continue
        heapq.heappush(pq, (adjDist, adjNode, univType[node], univType[adjNode]))  # MST 집합에 추가

    if (cnt == N):  # 최소 간선을 제외한 간선이 (노드개수-1)개만큼 선택되었다면 MST 구축이 완료된 것이므로 루프 탈출
        sys.exit(print(totalDist))

print(-1)