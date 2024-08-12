import sys

n = int(input())

weight = list(map(int, sys.stdin.readline().strip().split()))

sorted_weight = sorted(weight, reverse=True)

count = 0

for i in range(n-1, -1, -1):
    if weight[i] == sorted_weight[count]:
        count += 1

print(n - count)