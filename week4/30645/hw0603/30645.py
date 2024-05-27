from collections import deque
import sys

R, C = map(int, sys.stdin.readline().strip().split())
N = int(sys.stdin.readline())
q = deque(sorted(map(int, sys.stdin.readline().strip().split())))

if (N <= C):
    sys.exit(print(N))

matrix = [[None] * C for _ in range(R)]

def fillMatrix():
    matrix[0] = [q.popleft() for _ in range(C)]
    for i in range(1, R):
        for j in range(C):
            while (q):
                e = q.popleft()
                if (matrix[i-1][j] < e):
                    matrix[i][j] = e
                    break

fillMatrix()

cnt = 0
for j in range(C):
    cnt += len(set(matrix[i][j] for i in range(R) if matrix[i][j]))
print(cnt)