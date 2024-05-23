import sys

N, M = map(int, sys.stdin.readline().split())
a, b, c = map(int, sys.stdin.readline().split())
matrix = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

# 제일 왼쪽 위 좌표 기준으로 생성
# 1. 일단 가로로 긴거
def generatePositions1(row, col):
    result = []
    # 차
    for i in range(a):
        for j in range(b):
            nr, nc = row+i, col+j
            if not (0 <= nr < N and 0 <= nc < M):
                return None
            result.append((nr, nc))
    
    # 트레일러
    col += b
    for i in range(a):
        for j in range(c):
            nr, nc = row+i, col+j
            if not (0 <= nr < N and 0 <= nc < M):
                return None
            result.append((nr, nc))

    return result

def validBound(row, col):
    return 0 < row <= N and 0 < col <= M 

def diff1(row, col):
    minusPositions = []
    for nr in range(row, row+a):
        minusPositions.append((nr, col))
    return minusPositions

def diff2(row, col):
    minusPositions = []
    for nr in range(row, row+a):
        minusPositions.append((nr, col))
    for nr in range(row+a, row+a+b):
        minusPositions.append((nr, col+c))
    return minusPositions

def diff3(row, col):
    minusPositions = []
    for nr in range(row, row+a):
        minusPositions.append((nr, col))
    for nr in range(row+a, row+a+c):
        minusPositions.append((nr, col+b))
    return minusPositions

# 2. 트레일러 시작 ㄱ자
def generatePositions2(row, col):
    result = []
    # 트레일러
    for i in range(a):
        for j in range(c):
            nr, nc = row+i, col+j
            if not (0 <= nr < N and 0 <= nc < M):
                return None
            result.append((nr, nc))
    
    # 차
    row += a
    col += c
    for i in range(b):
        for j in range(a):
            nr, nc = row+i, col+j
            if not (0 <= nr < N and 0 <= nc < M):
                return None
            result.append((nr, nc))
    
    return result

# 3. 차 시작 ㄱ자
def generatePositions3(row, col):
    result = []
    # 차
    for i in range(a):
        for j in range(b):
            nr, nc = row+i, col+j
            if not (0 <= nr < N and 0 <= nc < M):
                return None
            result.append((nr, nc))
    
    # 트레일러
    row += a
    col += b
    for i in range(c):
        for j in range(a):
            nr, nc = row+i, col+j
            if not (0 <= nr < N and 0 <= nc < M):
                return None
            result.append((nr, nc))
    
    return result

# 좌표 리스트를 받아서 흐림 정도의 합을 반환
def calculateDimmingValue(coords: list):
    if not (coords):
        return sys.maxsize
    result = sum(matrix[i][j] for i, j in coords)
    return result

minValue = sys.maxsize
# for i in range(N):
#     for j in range(M):
#         minValue = min(minValue, calculateDimmingValue(generatePositions1(i, j)))
#         minValue = min(minValue, calculateDimmingValue(generatePositions2(i, j)))
#         minValue = min(minValue, calculateDimmingValue(generatePositions3(i, j)))

# print(minValue)


def plus2(row, col):
    plusPositions = []
    for nr in range(row, row+a):
        plusPositions.append((nr, col+c))
    for nr in range(row+a, row+a+b):
        plusPositions.append((nr, col+c+1))
    return plusPositions

def plus3(row, col):
    plusPositions = []
    for nr in range(row, row+a):
        plusPositions.append((nr, col+b))
    for nr in range(row+a, row+a+c):
        plusPositions.append((nr, col+b+1))
    return plusPositions


# 첫번째 ㅡ 자: b+c 만큼 더해짐
for i in range(N-a+1):
    curRowInitial = calculateDimmingValue(generatePositions1(i, 0))
    minValue = min(minValue, curRowInitial)
    for j in range(1, M-(b+c)+1):
        curRowInitial -= calculateDimmingValue(diff1(i, j-1))
        curRowInitial += calculateDimmingValue(diff1(i, j-1+(b+c)))
        minValue = min(minValue, curRowInitial)

# 두번째: 
for i in range(N-(a+b)+1):
    curRowInitial = calculateDimmingValue(generatePositions2(i, 0))
    minValue = min(minValue, curRowInitial)
    for j in range(1, M-(c+a)+1):
        curRowInitial -= calculateDimmingValue(diff2(i, j-1))
        curRowInitial += calculateDimmingValue(plus2(i, j-1))
        minValue = min(minValue, curRowInitial)

# 세번째: 
for i in range(N-(a+c)+1):
    curRowInitial = calculateDimmingValue(generatePositions3(i, 0))
    minValue = min(minValue, curRowInitial)
    for j in range(1, M-(b+a)+1):
        curRowInitial -= calculateDimmingValue(diff3(i, j-1))
        curRowInitial += calculateDimmingValue(plus3(i, j-1))
        minValue = min(minValue, curRowInitial)

print(minValue)