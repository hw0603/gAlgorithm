import sys
import heapq

n = int(input())

processes = [[0, 0, 0] for _ in range(n)]

result = []

for i in range(n):
    processes[i] = list(map(int, sys.stdin.readline().strip().split()))

hq = []

index = 0
time = 0

while True:
    while index < n and processes[index][0] <= time:
        t, p, b = processes[index]
        heapq.heappush(hq, [-1 * (p - t), b, t, index+1])
        index += 1

    if hq:
        cur = heapq.heappop(hq)

        result.append(cur[3])
        
        time += cur[1]
    else:
        time += 1

    if index == n and not hq:
        break

print(*result)