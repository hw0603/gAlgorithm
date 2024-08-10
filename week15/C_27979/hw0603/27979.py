import heapq
from collections import deque
import sys

N = int(sys.stdin.readline())
balls = deque(map(int, sys.stdin.readline().split()))

heap_buffer = []
cnt, p0 = 0, -sys.maxsize
while (balls):
    pos = balls.popleft()
    if (pos >= p0):  # 순서 맞는 경우
        heapq.heappush(heap_buffer, (p0 := pos))  # 나중에 쓰일수도있으니 버퍼에 다 넣어둠
        continue

    # 순서 어긋난 애를 처음 만나면 고쳐 줌
    maxVal = pos
    cnt += 1
    while (balls and (balls[0] < p0)):
        maxVal = max(maxVal, balls.popleft())
        cnt += 1
    
    # 순서 어긋난 걸 고치면 같이 고쳐야만 하는 것들 세 줌
    while (heap_buffer and heap_buffer[0] < maxVal):
        x = heapq.heappop(heap_buffer)
        cnt += 1
    
    p0 = balls[0] if balls else p0  # 이제 p0 왼쪽애들은 다 정리됐으니 기준점 업데이트

print(cnt)
