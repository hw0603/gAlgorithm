from collections import deque
import sys

N, D = map(int, sys.stdin.readline().strip().split())
monster, item = [], []

for _ in range(N):
    roomType, value = map(int, sys.stdin.readline().strip().split())
    (monster if roomType % 2 else item).append(value)
monster.sort()
item.sort()

monster = deque(monster)
item = deque(item)
itemCnt = len(item)

breakedRooms = 0
while (monster):
    monsterCnt = 0
    while (monster and monster[0] < D):
        D += monster.popleft()
        monsterCnt += 1
    breakedRooms += monsterCnt

    # 남은 장비가 없는데 더 이상 이길 수 있는 몬스터가 없으면 종료
    if (monsterCnt == 0 and not item):
        break
    
    # 장비 남아 있으면 먹음
    if (item):
        D *= item.popleft()

print(breakedRooms + itemCnt)
