s = input()

sliced = []
count = 0
prev = False

for i in range(len(s)):
    if s[i].isupper() == prev:
        count += 1
    else:
        sliced.append(count)
        count = 1
        prev = s[i].isupper()
    if i == len(s) - 1:
        sliced.append(count)

n = len(sliced)

on = [0 for _ in range(n)]
off = [0 for _ in range(n)]

on[0], off[0] = sliced[0] + 1, sliced[0]

for i in range(1, n):
    c = sliced[i]
    if i != n - 1:
        if i % 2 == 0:
            on[i] = min(on[i-1] + 2 + c, on[i-1] + c * 2, off[i-1] + c + 1)
            off[i] = min(on[i-1] + 1 + c, off[i-1] + c)
        else:
            on[i] = min(on[i-1] + c, off[i-1] + 1 + c)
            off[i] = min(on[i-1] + c + 1, off[i-1] + 2 + c, off[i-1] + c * 2)
    else:
        if i % 2 == 0:
            off[i] = min(on[i-1] + 1 + c, off[i-1] + c)
            on[i] = off[i] + 1
        else:
            on[i] = min(on[i-1] + c, off[i-1] + 1 + c)
            off[i] = on[i] + 1

print(min(on[n-1], off[n-1]))