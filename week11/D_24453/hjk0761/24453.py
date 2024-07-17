import sys

n, m = map(int, input().split())

error = list(map(int, sys.stdin.readline().strip().split()))

x, y = map(int, input().split())

left, right = 0, 1

result = 0

while right <= m:
    if right - left < y:
        right += 1
    else:
        lower = error[left - 1] if left > 0 else 0
        upper = error[right] - 1 if right < m else n
        if upper - lower < x:
            right += 1
        else:
            result = max(result, m - right + left)
            left += 1

print(result)