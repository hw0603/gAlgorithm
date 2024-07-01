from collections import deque
import sys

N = int(sys.stdin.readline())
initial = list(sys.stdin.readline().strip().split())
data = {}
impact = {}

target = (1 << N+1) - 2
initial = int(''.join(reversed(initial))+'0', base=2)

for switch in range(1, N+1):
    _, *data[switch] = map(int, sys.stdin.readline().strip().split())
    data[switch] = set(data[switch])

    mask = 0
    for pos in data[switch]:
        mask |= (1 << pos)  # 간접적으로 켜지는 스위치
    impact[switch] = (mask | (1 << switch))  # 직접 켜진 스위치


# 특정 스위치를 켜고 결과값을 반환
def switchOn(switchNum: int, currentNum: int) -> int:
    return currentNum ^ impact[switchNum]


visited = set([initial])
q = deque([initial])
toggleCnt = 0
while (q):
    for _ in range(len(q)):
        num = q.popleft()
        if (num == target):
            sys.exit(print(toggleCnt))
        
        # 켤수있는 스위치 다 켜봄
        for sw in range(1, N+1):
            if (num & (1 << sw)):
                continue
            newNum = switchOn(sw, num)
            if (newNum in visited):
                continue
            visited.add(newNum)
            q.append(newNum)
    toggleCnt += 1

print(-1)
