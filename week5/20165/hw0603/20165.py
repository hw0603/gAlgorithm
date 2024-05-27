from collections import deque
import sys

N, M, R = map(int, sys.stdin.readline().strip().split())
matrix = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(N)]
isStanding = [[True] * M for _ in range(N)]
directions = {
    "E": (0, 1),
    "W": (0, -1),
    "S": (1, 0),
    "N": (-1, 0)
}

score = 0
for round in range(2*R):
    operation = sys.stdin.readline().strip().split()
    
    if (round % 2):  # 수비수
        row, col = map(int, operation)
        row -= 1
        col -= 1
        isStanding[row][col] = True  # 걍 세우면 됨

    else:  # 공격수
        row, col, dir = int(operation[0]), int(operation[1]), operation[2]
        row -= 1
        col -= 1
        dir = directions[dir]

        q = deque([(row, col)])
        while (q):
            r, c = q.popleft()
            if not (isStanding[r][c]):
                continue  # 이미 넘어져 있으면 Skip
            isStanding[r][c] = False  # 넘어뜨리고
            score += 1  # 점수 증가
            chainCount = matrix[r][c]  # 자기 자리 포함 이만큼 넘어져야 함
            for i in range(1, chainCount):
                nr, nc = r+(dir[0]*i), c+(dir[1]*i)
                if not (0 <= nr < N and 0 <= nc < M):
                    continue
                if not (isStanding[nr][nc]):
                    continue
                q.append((nr, nc))

print(score)
for line in isStanding:
    print(*map(lambda x: "S" if x else "F", line))
