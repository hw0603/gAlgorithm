import sys

n, l = map(int, input().split())

light = list(map(int, sys.stdin.readline().strip().split()))
light.sort()

result = 0

if n != 1:
    for i in range(n-1):
        if i == 0:
            if light[i] > light[i+1] - l:
                result += light[i] - light[i+1] + l
            if light[i] + l > light[i+1] - l:
                result += light[i] + l - max(light[i], light[i+1] - l)
            continue
        if light[i] + l > light[i+1] - l:
            result += light[i] + l - max(light[i+1] - l, light[i-1] + l)

print(result)