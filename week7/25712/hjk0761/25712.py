import sys

n, m = map(int, input().split())

row_infos = list(map(int, sys.stdin.readline().strip().split()))
prev_row_info = []
flag = [dict() for _ in range(m)]

row_info = list(map(int, sys.stdin.readline().strip().split()))
prev_row_info = row_info

for j in range(row_infos[0]//2):
    start, end = row_info[2 * j], row_info[2 * j + 1]
    flag[0][2 * j] = True

for i in range(1, m):
    row_info = list(map(int, sys.stdin.readline().strip().split()))
    for j in range(row_infos[i]//2):
        start, end = row_info[2 * j], row_info[2 * j + 1]
        for k in range(row_infos[i-1]//2):
            prev_start, prev_end = prev_row_info[2 * k], prev_row_info[2 * k + 1]
            if start > prev_end or end < prev_start or flag[i-1][2 * k] == False:
                flag[i][2 * j] = False
            else:
                flag[i][2 * j] = True
                break
    prev_row_info = row_info

possible = False

for i in range(row_infos[-1]//2):
    if flag[-1][2 * i] == True:
        possible = True
        break

if possible == False:
    print("NO")
else:
    print("YES")