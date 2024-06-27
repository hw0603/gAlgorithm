import sys

n, m, k = map(int, input().split())

animation = list(map(int, sys.stdin.readline().strip().split()))

animation.sort(reverse=True)

def cal(arr, index, k):
    temp = 0
    for i in range(index, n, k):
        temp += arr[i]
    return temp


def find(left, right):
    mid = (left + right) // 2
    while left <= right:
        time = cal(animation, mid, k)
        if time <= m:
            return find(left, mid-1)
        else:
            return find(mid+1, right)
    return left

print(n - find(0, n-1))