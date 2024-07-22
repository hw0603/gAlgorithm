import sys

n, q = map(int, input().split())

tree = list(map(int, sys.stdin.readline().strip().split()))

tree.sort()

prefix = [0 for _ in range(n+1)]

for i in range(n):
    prefix[i+1] = prefix[i] + tree[i]

def find(left, right):
    global x
    mid = (left + right) // 2
    if left >= right:
        return right
    if x > tree[mid]:
        return find(mid+1, right)
    else:
        return find(left, mid)

for i in range(q):
    x = int(sys.stdin.readline().strip())
    index = find(0, n)
    score1 = index * x - prefix[index]
    score2 = prefix[n] - prefix[index] - x * (n - index)
    score = score1 + score2
    print(score)