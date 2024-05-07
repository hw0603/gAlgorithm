import sys

N, M = map(int, sys.stdin.readline().split())
data = list(map(int, sys.stdin.readline().split()))

left, right = 0, 0  # [left, right)
partSum = 0
result = 0
while (right < N):
    # 하나 더 더할 수 있으면 오른쪽 포인터 옮기고 더함
    if (partSum + data[right] <= M):
        partSum += data[right]
        right += 1
        
    # 더할 수 없으면 왼쪽 포인터 옮겨서 부분합 감소
    else:
        partSum -= data[left]
        left += 1

    result = max(result, partSum)

print(result)
