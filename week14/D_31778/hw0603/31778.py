from itertools import accumulate
import heapq
import sys

N, K = map(int, sys.stdin.readline().strip().split())
arr = list(map(lambda x: 1 if x == 'P' else 0, list(sys.stdin.readline().strip())))

oneIdx, zeroIdx = [], []
for i, num in enumerate(arr):
    heapq.heappush(*((oneIdx, -i) if num == 1 else (zeroIdx, i)))
oneCount = len(oneIdx)

# P로만 이루어져 있거나 C로만 이루어져 있으면 종료
if not (oneIdx and zeroIdx):
    sys.exit(print(0))

# 제일 뒤에 있는 1이랑 제일 앞에 있는 0 swap
for _ in range(K):
    lastOneIdx = -heapq.heappop(oneIdx)
    firstZeroIdx = heapq.heappop(zeroIdx)
    arr[lastOneIdx], arr[firstZeroIdx] = arr[firstZeroIdx], arr[lastOneIdx]
    heapq.heappush(zeroIdx, lastOneIdx)
    heapq.heappush(oneIdx, -firstZeroIdx)

    # 111...000 형태가 미리 만들어진 경우 루프 종료
    if (zeroIdx[0] == oneCount):
        break

acc1Count = list(accumulate(arr))

result = 0
for i in range(N):
    if (arr[i]):
        continue
    result += acc1Count[i] * (acc1Count[i]-1) // 2

print(result)
