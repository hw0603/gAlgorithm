from collections import defaultdict
import datetime
import sys

N, M = map(int, sys.stdin.readline().strip().split())

def dictFactory():
    return {k: [datetime.timedelta(), 0] for k in range(1, M//7 + 1)}
data = defaultdict(dictFactory)  # data[name][week][0: runningTime | 1: refCnt]

for _ in range(N):
    name, day, start, end = sys.stdin.readline().strip().split()
    start, end = list(map(int, start.split(":"))), list(map(int, end.split(":")))
    start = datetime.timedelta(hours=start[0], minutes=start[1])
    end = datetime.timedelta(hours=end[0], minutes=end[1])
    runningTime = end - start

    week = (int(day)-1) // 7 + 1  # 주차 번호
    data[name][week][0] += runningTime  # 해당 주차의 방송 시간 누적
    data[name][week][1] += 1  # 해당 주차의 방송 카운트 누적

def checkCondition(runnginTimeAndRefCnt: list[datetime.timedelta, int]):
    return runnginTimeAndRefCnt[0] >= datetime.timedelta(hours=60) and runnginTimeAndRefCnt[1] >= 5

# data[name]의 모든 week에 대해.. 만족해야 함
answer = (
    name for name in data
        if all(map(checkCondition, data[name].values()))
)
print('\n'.join(sorted(answer)) if answer else -1)
