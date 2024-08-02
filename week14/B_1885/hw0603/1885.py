import sys

n, k = map(int, sys.stdin.readline().split())
arr = [int(sys.stdin.readline()) for _ in range(n)]

count = 0
tmp = set()
for num in arr:
    tmp.add(num)
    if (len(tmp) == k):
        tmp = set()
        count += 1

print(count+1)
