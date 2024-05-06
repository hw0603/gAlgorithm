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

lb = arr[-M] if N >= M else 1  # 분배 가능한 길이 중 제일 작은 값
ub = arr[-1]  # 분배 불가능하다고 확정지을 수 있는 값 중 제일 큰 값

while (ub - lb > 1):
    mid = (lb+ub) // 2
    if (isDistributable(mid)):
        lb = mid
    else:
        ub = mid

print(lb)
