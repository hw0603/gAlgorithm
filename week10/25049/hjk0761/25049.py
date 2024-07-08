import sys

n = int(input())

playlist = list(map(int, sys.stdin.readline().strip().split()))

forward_subarray = [0 for _ in range(n)]

temp = 0
for i in range(n):
    if i == 0:
        forward_subarray[i] = max(0, playlist[i])
        temp = max(0, playlist[i])
    else:
        forward_subarray[i] = max(forward_subarray[i-1], playlist[i] + temp)
        if playlist[i] >= 0:
            temp += playlist[i]
        else:
            temp = max(0, temp + playlist[i])

backward_subarray = [0 for _ in range(n)]

temp = 0
for i in range(n-1, -1, -1):
    if i == n-1:
        backward_subarray[i] = max(0, playlist[i])
        temp = max(0, playlist[i])
    else:
        backward_subarray[i] = max(backward_subarray[i+1], playlist[i] + temp)
        if playlist[i] >= 0:
            temp += playlist[i]
        else:
            temp = max(0, temp + playlist[i])

_max = 0

for i in range(n-1):
    _max = max(_max, forward_subarray[i] + backward_subarray[i+1])

_max = max(_max, forward_subarray[n-1])
_max = max(_max, backward_subarray[0])

print(sum(playlist) + _max)