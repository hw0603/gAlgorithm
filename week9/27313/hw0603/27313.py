from collections import deque
import sys

N, M, K = map(int, sys.stdin.readline().split())
arr = sorted(ani for ani in map(int, sys.stdin.readline().strip().split()) if ani <= M)

buffer = deque()
answer = 0

for ani in arr:
    if (len(buffer) < K):  # 버퍼가 덜 채워졌으면 채움
        buffer.append(ani)
    else:
        # 버퍼가 다 찼다면 더 이상 같이 묶을 수 없음 -> 제일 짧은 애니 하나를 앞 그룹으로 보내고
        # 앞으로 보내진 값이 해당 그룹의 대표값이 될 것이므로 (대표값+현재 애니의 러닝타임) 을 큐에 삽입
        if (buffer[0] + ani > M):
            break
        else:
            buffer.append(buffer.popleft() + ani)
    
    answer += 1

print(answer)
