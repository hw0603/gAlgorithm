from collections import deque
import sys

dr = (0, 0, 1, -1)
dc = (1, -1, 0, 0)

N = int(sys.stdin.readline())
# matrix = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(N)]
matrix = []
maxVal, minVal = -1, sys.maxsize
for _ in range(N):
    line = list(map(int, sys.stdin.readline().strip().split()))
    maxVal = max(maxVal, max(line))
    minVal = min(maxVal, min(line))
    matrix.append(line)

import random, time
N = 500
matrix = [[random.randrange(1, 1000000000)] * N for _ in range(N)]
maxVal = max(map(max, matrix))
minVal = min(map(min, matrix))

# 결정 함수: 최대 경사를 전달받고 목적지에 도달 가능 여부를 반환
def check(maxDiff: int) -> bool:
    visited = [[False] * N for _ in range(N)]
    visited[0][0] = True
    q = deque([(0, 0)])
    while (q):
        row, col = q.popleft()
        for i in range(4):
            nr, nc = row+dr[i], col+dc[i]
            if not (0 <= nr < N and 0 <= nc < N):
                continue
            if (visited[nr][nc]):
                continue
            if (abs(matrix[row][col] - matrix[nr][nc]) > maxDiff):
                continue
            if ((nr, nc) == (N-1, N-1)):
                return True
            visited[nr][nc] = True
            q.append((nr, nc))
    
    return False


# 매개 변수 탐색: F F F F 'T' T T 찾기
def search():
    half_gen = lambda N: (N >> i for i in range(N.bit_length()))
    low, high = 0, maxVal - minVal
    cur = low-1
    
    for step in half_gen(high-low+1):
        while (cur+step <= high and not check(cur+step)):
            cur += step
    return cur+1

def search2():
    low, high = 0, maxVal - minVal
    answer = 0
    while (low <= high):
        mid = (low+high) // 2
        if (check(mid) == True):
            answer = mid
            high = mid - 1
        else:
            low = mid + 1

    return answer

t = time.time()
print(search())
print(time.time() - t)

t = time.time()
print(search2())
print(time.time() - t)

