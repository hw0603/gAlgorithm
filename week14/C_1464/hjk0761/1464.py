from collections import deque

s = input()

q = deque()

for c in s:
    if not q:
        q.append(c)
    else:
        if ord(q[0]) < ord(c):
            q.append(c)
        else:
            q.appendleft(c)

print(''.join(q))