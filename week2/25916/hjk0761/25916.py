import sys

n, m = map(int, input().split())
a = list(map(int, sys.stdin.readline().strip().split()))

_max = 0
left, right, _sum = 0, 0, a[0]
while True:
    if _sum > _max and _sum <= m:
        _max = _sum
    if _sum == m:
        break
    elif _sum < m:
        if right == len(a) - 1:
            break
        right += 1
        _sum += a[right]
    else:
        if left == len(a) - 1:
            break
        _sum -= a[left]
        left += 1
print(_max)