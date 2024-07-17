import sys

N = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().strip().split()))
left, right = [], []

for item in arr:
    left.append(1 if item == 1 else -1)
    right.append(1 if item == 2 else -1)


ldp = [left[0]] + [-sys.maxsize] * (N-1)
rdp = [right[0]] + [-sys.maxsize] * (N-1)
lmax = ldp[0]
rmax = rdp[0]
for i in range(1, N):
    ldp[i] = max(ldp[i-1] + left[i], left[i])
    lmax = max(lmax, ldp[i])
    rdp[i] = max(rdp[i-1] + right[i], right[i])
    rmax = max(rmax, rdp[i])

print(max(lmax, rmax))
