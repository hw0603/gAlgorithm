import sys

n, k = map(int, input().split())

count = [False for _ in range(k)]
result = 1

for _ in range(n):
    c = int(sys.stdin.readline().strip())
    count[c-1] = True
    if False not in count:
        result += 1
        count = [False for _ in range(k)]

print(result)