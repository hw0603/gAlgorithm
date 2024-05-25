import sys

n, m = map(int, input().split())
a, b, c = map(int, input().split())

field = [[0 for _ in range(m+1)] for _ in range(n)]

_min = 1000000000

for i in range(n):
    temp = list(map(int, sys.stdin.readline().strip().split()))
    field[i][1] = temp[0]
    for j in range(2, m+1):
        field[i][j] = field[i][j-1] + temp[j-1]

for i in range(n-a+1):
    for j in range(m-(b+c)+1):
        temp = 0
        for k in range(i, i+a):
            temp += field[k][j+b+c] - field[k][j]
        _min = min(_min, temp)

for i in range(n-(a+b)+1):
    for j in range(m-(c+a)+1):
        temp = 0
        for k in range(i, i+a):
            temp += field[k][j+c] - field[k][j]
        for k in range(i+a, i+a+b):
            temp += field[k][j+c+a] - field[k][j+c]
        _min = min(_min, temp)

for i in range(n-(a+c)+1):
    for j in range(m-(b+a)+1):
        temp = 0
        for k in range(i, i+a):
            temp += field[k][j+b] - field[k][j]
        for k in range(i+a, i+a+c):
            temp += field[k][j+b+a] - field[k][j+b]
        _min = min(_min, temp)

print(_min)