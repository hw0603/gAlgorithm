import sys

n = int(input())

score = list(map(int, sys.stdin.readline().strip().split()))
score.sort()

p, q, r, s = map(int, sys.stdin.readline().strip().split())

def cal(k):
    global p, q, r
    temp = 0
    for i in range(n):
        temp += score[i]
        if score[i] < k:
            temp += q
        elif score[i] > k + r:
            temp -= p
    return temp

def find(left, right):
    global s
    mid = (left + right) // 2
    if left >= right:
        return right
    temp_score = cal(mid)
    if temp_score < s:
        return find(mid+1, right)
    else:
        return find(left, mid)

result = find(1, score[-1]+2)

print(result if result < score[-1]+2 else -1)