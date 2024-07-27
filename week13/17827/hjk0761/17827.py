import sys

n, m, v = map(int, sys.stdin.readline().strip().split())

snail = list(map(int, sys.stdin.readline().strip().split()))

result = []

for _ in range(m):
    k = int(sys.stdin.readline().strip())
    if k < n:
        result.append(snail[k])
    else:
        if v == n:
            result.append(snail[n-1])
        else:
            index = ((k - n) % (n - v + 1) + v)
            result.append(snail[index-1])

for answer in result:
    print(answer)