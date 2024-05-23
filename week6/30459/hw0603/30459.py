from itertools import combinations
import sys

N, M, R = map(int, sys.stdin.readline().split())
positions = sorted(map(int, sys.stdin.readline().split()))
flag_poles = list(map(int, sys.stdin.readline().split()))
answer = -1
base_lines = sorted(set(abs(p2 - p1) for p1, p2 in combinations(positions, 2)))

def half_gen(N):
    while (N):
        yield N
        N //= 2

def check(number, pole):
    return base_lines[number] * pole <= 2*R

for pole in flag_poles:  # 모든 깃대에 대해 조사
    # T T T T T F F F 에서 마지막 T 찾기
    # check() | ans = cur

    # base_lines 에 하나밖에 없을 때 처리.. 깔끔하게 안되나?
    if (len(base_lines) == 1):
        if (check(0, pole)):
            answer = max(answer, base_lines[0] * pole)
        continue

    low, high = 0, len(base_lines)-1
    cur = low-1

    for step in half_gen(high):
        while (cur+step <= high and check(cur+step, pole)):
            cur += step
    
    # 구간 내 정답이 존재하면 최댓값 갱신
    if (cur != low-1):
        answer = max(answer, base_lines[cur] * pole)

if (answer == -1):
    sys.exit(print(-1))
print("%.1f" % (answer / 2))
