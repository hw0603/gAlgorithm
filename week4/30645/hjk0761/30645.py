import sys

r, c = map(int, input().split())
n = int(input())
doll = list(map(int, sys.stdin.readline().strip().split()))
doll.sort()

count = 0
index = 0
prev_height = [0 for _ in range(c)]

for i in range(n):
    if count >= r * c:
        break
    if doll[i] > prev_height[index]:
        count += 1
        prev_height[index] = doll[i]
        index = (index + 1) % c
    else:
        continue

print(count)