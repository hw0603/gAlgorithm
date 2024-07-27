import sys

t = int(input())

results = []

def count(left, right):
    return (right - left) * (right - left - 1) // 2

def find(li):
    result = 0

    left, right = 0, 0

    while right <= len(li):
        if right == len(li):
            result += count(left, right)
            break
        if left >= right:
            right += 1
            continue
        if right - left == 1:
            if li[left] != li[right]:
                right += 1
            else:
                left += 1
        else:
            if (li[right-2] - li[right-1]) * (li[right-1] - li[right]) < 0:
                right += 1
            else:
                result += count(left, right)
                left = right - 1
    return result

for _ in range(t):
    n = int(sys.stdin.readline().strip())
    zigzag = list(map(int, sys.stdin.readline().strip().split()))
    results.append(find(zigzag))

for c in results:
    print(c)