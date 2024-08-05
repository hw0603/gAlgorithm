import sys
from collections import deque

s = input()
dq = deque()
dq.append(s[0])
for c in s[1:]:
    if dq[0] >= c:
        dq.appendleft(c)
    else:
        dq.append(c)
print(*dq, sep="")
