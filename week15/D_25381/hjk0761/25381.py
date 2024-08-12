import sys
from collections import deque

s = list(sys.stdin.readline().strip())

q = deque()
count = 0
b = 0

for i in range(len(s)):
    if s[i] == 'B':
        q.append(1)
        b += 1
    elif s[i] == 'C' and q:
        q.pop()
        count += 1

q = deque()

for i in range(len(s)):
    if s[i] == 'A':
        q.append(1)
    elif s[i] == 'B' and q:
        q.pop()
        count += 1

print(min(count, b))