from collections import deque
import sys

N = int(sys.stdin.readline())

q = deque(range(1, N))

result = []

while (len(q) >= 2):
    n1, n2 = q.pop(), q.pop()
    result.append(f'{n1} {n2}')
    newVal = abs(n1 - n2)

    q.appendleft(newVal)

last = q.pop()
print(N - last)
print(*result, sep='\n')
print(last, N)
