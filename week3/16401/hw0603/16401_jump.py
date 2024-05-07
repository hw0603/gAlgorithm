import sys

M, N = map(int, sys.stdin.readline().split())  # 조카수, 과자수
arr = sorted(map(int, sys.stdin.readline().split()))

def isDistributable(length: int) -> bool:
    distributed_people_count = 0
    for p in (num // length for num in reversed(arr)):  # Lazy Evaluation
        distributed_people_count += p
        if (distributed_people_count >= M):
            return True
        if (p == 0):
            return False

if (sum(arr) < M):
    sys.exit(print(0))

def half_gen(N):
    while (N):
        yield N
        N //= 2

low = arr[-M] if N >= M else 1
high = arr[-1]
cur = low - 1
for step in half_gen(high):
    while (cur + step <= high and isDistributable(cur + step)):
        cur += step

print(cur)
