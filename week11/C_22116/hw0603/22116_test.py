from collections import deque
import random, time

# 전역변수
dr = (0, 0, 1, -1)
dc = (1, -1, 0, 0)
N = 0
matrix = []
maxVal, minVal = 0, 0

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


# 매개 변수 탐색: F F F F 'T' T T 찾기 -> Binary Jump
def search():
    half_gen = lambda N: (N >> i for i in range(N.bit_length()))
    low, high = 0, maxVal - minVal
    cur = low-1
    
    for step in half_gen(high-low+1):
        while (cur+step <= high and not check(cur+step)):
            cur += step
    return cur+1

# 일반적으로 구현한 매개 변수 탐색
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


def expr():
    global N, matrix, maxVal, minVal

    # 실험 데이터 설정
    N = 500
    maxSlope = 100_000_000  # 1억
    matrix = [[random.randrange(1, maxSlope)] * N for _ in range(N)]
    maxVal = max(map(max, matrix))
    minVal = min(map(min, matrix))

    t = time.time()
    r1 = search()
    s1 = time.time() - t

    t = time.time()
    r2 = search2()
    s2 = time.time() - t

    print(s1, s2)
    result = float(s2 / maxSlope * 100)
    print("%f%%" % result)

    return result

TEST_CNT = 10
for _ in range(TEST_CNT):
    expr()


"""
Binary Jump 방식에서는 target이 구간의 끝쪽에 가까울수록 유리함
일반적인 구현해서는 target이 구간의 중간에 가까울수록 유리함
이번 문제는 target이 구간에서 극단적으로 앞쪽에 위치
-> 일반적인 구현에 비해 약 2배정도 시간이 느리게 측정되는 이유
"""
