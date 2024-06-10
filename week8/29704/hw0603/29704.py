import sys

N, T = map(int, sys.stdin.readline().split())
problem = [(0, 0)] + [tuple(map(int, sys.stdin.readline().split())) for _ in range(N)]
dp = [[0] * (T+1) for  _ in range(N+1)]  # dp[i][j]: i번째 문제까지 조사했을 때, 제한이 j일때 피할 수 있는 벌금의 최댓값

for i in range(1, N+1):  # 문제 번호
    for limit in range(1, T+1):  # 일자 제한
        if (problem[i][0] > limit):  # 현재 조사하는 문제의 소요일이 현재 제한값보다 크면
            dp[i][limit] = dp[i-1][limit]  # 현재 문제는 선택하지 못하므로 예전 dp값 불러와서 씀
        else:  # 제한이 현재 문제보다 커서 적어도 현재 문제 하나는 선택할 수 있는 경우
            # 선택하지 않는 경우와 선택하는 경우 둘 중 가치가 높은 경우를 택함
            dp[i][limit] = max(dp[i-1][limit], dp[i-1][limit - problem[i][0]] + problem[i][1])

totalFine = sum(map(lambda x: x[1], problem))
print(totalFine - dp[-1][-1])  # 최적 벌금 = 벌금 총합 - 최대로 피할 수 있는 벌금
