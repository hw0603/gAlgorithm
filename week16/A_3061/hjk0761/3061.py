import sys

t = int(input())

result = []

for _ in range(t):
    n = int(sys.stdin.readline().strip())
    ladder = list(map(int, sys.stdin.readline().strip().split()))
    
    count = 0

    for i in range(n):
        changed = False
        for j in range(n - 1 - i):
            if ladder[j] > ladder[j+1]:
                ladder[j], ladder[j+1] = ladder[j+1], ladder[j]
                count += 1
                changed = True
        if not changed:
            break

    result.append(count)

for re in result:
    print(re)