import sys

sys.stdin.readline()
arr = list(map(int, sys.stdin.readline().split()))

prev, minValue = 0, 10**9
print(*(prev := max(prev, num - (minValue := min(minValue, num))) for num in arr))
