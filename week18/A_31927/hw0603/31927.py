import sys

N = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().strip().split()))
result = []

"""arr[leftIdx-1] > arr[leftIdx]+x and arr[rightIdx]-x > arr[rightIdx+1] 인 x의 최댓값 k
즉.. arr[leftIdx-1] - arr[leftIdx] > x and arr[rightIdx] - arr[rightIdx+1] > x 인 x의 최댓값 k
즉... k = min(arr[leftIdx-1] - arr[leftIdx], arr[rightIdx] - arr[rightIdx+1], 1000000)
"""

for i in range(N//2):
    leftIdx, rightIdx = i, N-(i+1)
    if (leftIdx == 0):
        arr[leftIdx] += 1000000
        arr[rightIdx] -= 1000000
        result.append(arr[:])
        continue

    k = min(arr[leftIdx-1] - arr[leftIdx], arr[rightIdx] - arr[rightIdx+1], 1000000)
    arr[leftIdx] += k
    arr[rightIdx] -= k
    
    result.append(arr[:])


if (result and result[-1] != sorted(result[-1], reverse=True)):
    print(-1)
    sys.exit()
print(N//2)
for r in result:
    print(*r, sep=' ')
