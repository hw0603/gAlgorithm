import sys

N, K = map(int, sys.stdin.readline().split())
xts = (map(int, sys.stdin.readline().split()) for _ in range(K))
trafficLight = {x: (t, s) for x, t, s in xts}  # [좌표] -> (주기, 시작시간)

def calcOverhead(position: int, currnetTime: int):
    t, s = trafficLight[position]
    q, r = divmod(currnetTime - s, t)
    # 짝수면 초록불
    return t-r if q % 2 else 0

time = 0
totalOverhead = 0
prevLightPos = 0
for position in sorted(trafficLight.keys()):
    time += position - prevLightPos
    time += (overhead := calcOverhead(position, time))
    totalOverhead += overhead
    prevLightPos = position

print(totalOverhead + N)
