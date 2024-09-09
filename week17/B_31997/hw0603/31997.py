from itertools import accumulate
import sys

N, M, T = map(int, sys.stdin.readline().split())
ioData = {i+1: tuple(map(int, sys.stdin.readline().split())) for i in range(N)}
result = [0] * (T+1)

for i in range(M):
    c, d = map(int, sys.stdin.readline().split())  # c랑 d랑 친함

    # 둘이 못 만나면 Skip
    if (ioData[c][0] > ioData[d][1] or ioData[d][0] > ioData[c][1]):
        continue

    result[max(ioData[c][0], ioData[d][0])] += 1  # 나중에 입장한 애가 들어와야 쌍 성립
    result[min(ioData[c][1], ioData[d][1])] -= 1  # 먼저 퇴장한 애가 나가면 쌍 성립 해제

print(*list(accumulate(result))[:-1], sep='\n')
