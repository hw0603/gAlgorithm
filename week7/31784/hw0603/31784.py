import sys

N, K = map(int, sys.stdin.readline().strip().split())
arr = list(map(lambda x: ord(x) - 65, list(sys.stdin.readline().strip())))

needed = list(map(lambda x: (26 - x) % 26, arr))

for idx, neededMove in enumerate(needed):
    if (0 < neededMove <= K):
        K -= neededMove
        needed[idx] -= neededMove
        arr[idx] = (arr[idx] + neededMove) % 26

arr[-1] += (K % 26)
print(''.join(map(lambda x: chr(x+65), arr)))
