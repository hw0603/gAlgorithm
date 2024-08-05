n, k = map(int, input().split())

s = list(input())

left, right = 0, n-1

def findLeft(left):
    for i in range(left, n):
        if s[i] == 'C':
            return i
    return n

def findRight(right):
    for i in range(right, -1, -1):
        if s[i] == 'P':
            return i
    return -1

count = 0

while True:
    if count == k:
        break

    left, right = findLeft(left), findRight(right)

    if left >= right:
        break

    if left == n or right == -1:
        break

    s[left], s[right] = 'P', 'C'

    count += 1

result = 0
countP = [0 for _ in range(n+1)]

for i in range(n):
    if s[i] == 'P':
        countP[i+1] = countP[i] + 1
    else:
        countP[i+1] = countP[i]

for i in range(n-1, -1, -1):
    if s[i] == 'C':
        result += countP[i+1] * (countP[i+1] - 1) // 2

print(result)