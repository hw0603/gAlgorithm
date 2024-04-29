import sys

n, k = map(int, input().split())

light = [[0, 0, 0]] * k

def timeCost(t, s, currentTime):
    if currentTime < s:
        return s - currentTime
    else:
        timeGap = currentTime - s
        if (timeGap//t) % 2 == 0:
            return 0
        return t - timeGap % t
if k > 0:
    for i in range(k):
        light[i] = list(map(int, sys.stdin.readline().strip().split()))
    light.sort()

    time = 0
    position = 0

    for x, t, s in light:
        time += x - position
        tempTime = time
        position = x
        time += timeCost(t, s, time)

    time += n - light[-1][0]

    print(time)
else:
    print(n)