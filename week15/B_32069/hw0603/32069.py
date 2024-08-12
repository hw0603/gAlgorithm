from collections import deque
import sys

L, N, K = map(int, input().split())  # 도로 길이, 가로등 개수, 출력할 위치 개수

visited = set(map(int, sys.stdin.readline().strip().split())) 
q = deque(((e, 0) for e in visited))  # (pos, dist)


result = []
while (q):
    pos, dist = q.popleft()
    result.append(dist)    
    # K개의 위치를 모두 추가하면 BFS 종료
    if (len(result) == K):
        break
    
    for dp in {-1, 1}:  # dp: delta of pos
        nextPos = pos + dp
        if not (0 <= nextPos <= L):
            continue
        if (nextPos in visited):
            continue        

        q.append((nextPos, dist + 1))
        visited.add(nextPos)

print(*result, sep='\n')
