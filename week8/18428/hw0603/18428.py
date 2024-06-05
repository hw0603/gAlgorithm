from itertools import combinations
import sys

dr = (0, 0, 1, -1)
dc = (1, -1, 0, 0)

N = int(sys.stdin.readline())
matrix = [sys.stdin.readline().strip().split() for _ in range(N)]

def parseData() -> tuple[list[str], list[str]]:
    teachers = []
    students = []
    for i in range(N):
        for j in range(N):
            match (matrix[i][j]):
                case 'T':
                    teachers.append((i, j))
                case 'S':
                    students.append((i, j))
    
    return teachers, students

def calcCandidates(teachers: list) -> list:
    candidates = set()
    for row, col in teachers:
        for i in range(4):
            nr, nc = row, col
            while (0 <= nr+dr[i] < N and 0 <= nc+dc[i] < N):
                nr, nc = nr+dr[i], nc+dc[i]
                if (matrix[nr][nc] == 'X'):
                    candidates.add((nr, nc))
    return candidates

def check(*coords) -> bool:
    obs = set(coords)
    for row, col in teachers:
        for i in range(4):
            nr, nc = row, col
            while (0 <= nr+dr[i] < N and 0 <= nc+dc[i] < N):
                nr, nc = nr+dr[i], nc+dc[i]
                if ((nr, nc) in obs):
                    break
                if (matrix[nr][nc] == 'S'):
                    return False
    return True

teachers, students = parseData()
candidates = calcCandidates(teachers)
isHidable = any(check(*coords) for coords in combinations(candidates, 3))
print("YES" if isHidable else "NO")
