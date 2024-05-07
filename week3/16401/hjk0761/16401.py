import sys

m, n = map(int, input().split())

snack = list(map(int, sys.stdin.readline().strip().split()))

snack.sort(reverse = True)

left, right = 0, snack[0] + 1

def possible(l):
    count = 0
    for i in range(n):
        count += snack[i] // l
        if count >= m:
            return True
    return False

while True:
    mid = (left + right) // 2

    if mid == 0:
        print(mid)
        break

    if left >= right:
        print(mid - 1)
        break

    if possible(mid):
        left = mid + 1
    else:
        right = mid