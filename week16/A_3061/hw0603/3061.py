import sys

T = int(sys.stdin.readline())

def solve():
    N = int(sys.stdin.readline())
    arr = list(map(int, sys.stdin.readline().split()))

    cnt = 0
    for i in range(N-1, -1, -1):
        for j in range(i):
            if (arr[j] > arr[j+1]):
                arr[j], arr[j+1] = arr[j+1], arr[j]
                cnt += 1

    return cnt

print(*(solve() for _ in range(T)), sep='\n')
