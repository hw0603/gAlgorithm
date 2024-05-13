from itertools import combinations
import sys

N, K = map(int, sys.stdin.readline().strip().split())
lectures = []

for _ in range(N):
    weekday, start, end = map(int, sys.stdin.readline().strip().split())
    credit = end - start + 1
    if (weekday == 5):
        continue
    lectures.append((weekday, start, end, credit))


def timeCollideCheck(reserved_time: list, weekday: int, start: int, end: int):
    for t in range(start, end+1):
        if ((1 << t) & reserved_time[weekday]):
            return True
        reserved_time[weekday] |= (1 << t)
    return False

answer = 0
for lectureCount in range(1, N+1):
    for comb in combinations(lectures, lectureCount):
        reserved_time = [None, 0, 0, 0, 0]
        current_credit = 0
        for weekday, start, end, credit in comb:
            if (timeCollideCheck(reserved_time, weekday, start, end)):
                break
            current_credit += credit
        else:
            if (current_credit == K):
                answer += 1

print(answer)