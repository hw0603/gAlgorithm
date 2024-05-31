import sys

N, M = map(int, sys.stdin.readline().split())
rowLenght = list(map(int, sys.stdin.readline().split()))
data = [list() for _ in range(M)]

for i in range(M):
    line = list(map(int, sys.stdin.readline().split()))
    for j in range(0, len(line), 2):
        data[i].append((line[j], line[j+1]))
    

# print(*data, sep='\n')

def choose(a, b, c, d):
    if (a > d or b < c):
        return None  # 겹치는 부분이 없는 경우
    return (c, d)

# print()

current = data[0]
for rowIdx in range(1, M):
    # current와 rowIdx열을 비교해서 남은 경로를 current에 유지
    temp = set()
    for pos1 in current:
        for pos2 in data[rowIdx]:
            a, b = pos1
            c, d = pos2
            result = choose(a, b, c, d)
            if (result is not None):
                temp.add(result)
    current = list(temp)

print("YES" if current else "NO")
