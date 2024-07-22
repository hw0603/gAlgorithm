import sys

N, X = map(int, sys.stdin.readline().split())

burger = [1] * (N+1)  # burger[i] = Level-i 버거의 총 재료 개수
patty = [1] * (N+1)   # patty[i] = Levei-i 버거의 총 패티 개수

for i in range(1, N+1):
    burger[i] = 1 + burger[i-1] + 1 + burger[i-1] + 1  # B + f(N-1) + P + f(N-1) + B
    patty[i] = patty[i-1] + 1 + patty[i-1]


# Level-N 버거에서 X장을 먹었을 때, 먹은 패티의 개수
def eat(n: int, x: int) -> int:
    # 재귀 종료조건: Level-0 버거는 패티 하나만 있음
    if (n == 0):
        return 1
    
    """
    1. B -> 번만 먹음: 0
    2. B + f(n-1) -> 레벨 N-1 버거에서 x-1장(레벨 N버거의 B 빼고)을 먹음: eat(n-1, x-1)
    3. B + f(n-1) + P -> 레벨 N-1 버거 전체 패티수 + 1
    4. B + f(n-1) + P + f(n-1) -> (3)의 결과 + eat(n-1, x-(1+burger[n-1]+1))
    5. B + f(n-1) + P + f(n-1) + B -> 전체 다 먹음: 레벨 N 버거 패티 개수
    """
    
    # 1. 1개
    if (x == 1):
        return 0
    
    # 2. 1개 초과 ~ 중간 패티 전까지
    if (x <= 1 + burger[n-1]):
        return eat(n-1, x-1)
    
    # 3. 중간 패티 까지
    if (x == 1 + burger[n-1] + 1):
        return patty[n-1] + 1
    
    # 4. 중간 패티 초과 ~ 마지막 재료 전까지
    if (x <= 1 + burger[n-1] + 1 + burger[n-1]):
        return patty[n-1] + 1 + eat(n-1, x-(1+burger[n-1]+1))
    
    # 5. 전체 재료를 다 먹는 경우
    return patty[n]  # 레벨 N 버거의 패티 개수와 같음

print(eat(N, X))
